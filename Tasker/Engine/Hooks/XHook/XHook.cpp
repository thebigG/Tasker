#include "XHook.h"
#include "Timer.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <QApplication>
#include <QGuiApplication>
#include <QRegularExpression>
#include <QThread>
#include <QtCore>

using namespace Engine;

/* libUIOHook: Cross-platfrom userland keyboard and mouse hooking.
 * Copyright (C) 2006-2017 Alexander Barker.  All Rights Received.
 * https://github.com/kwhat/libuiohook/
 *
 * libUIOHook is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libUIOHook is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a co#py of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uiohook.h>
#include <wchar.h>
static XHookMode current_mode;

bool logger_proc(unsigned int level, const char *format, ...) {
    bool status = false;

    va_list args;
    switch (level) {
#ifdef USE_DEBUG
    case LOG_LEVEL_DEBUG:
    case LOG_LEVEL_INFO:
        va_start(args, format);
        status = vfprintf(stdout, format, args) >= 0;
        va_end(args);
        break;
#endif

    case LOG_LEVEL_WARN:
    case LOG_LEVEL_ERROR:
        va_start(args, format);
        status = vfprintf(stderr, format, args) >= 0;
        va_end(args);
        break;
    }

    return status;
}

// NOTE: The following callback executes on the same thread that hook_run() is
// called from.  This is important because hook_run() attaches to the operating
// systems event dispatcher and may delay event delivery to the target
// application. Furthermore, some operating systems may choose to disable your
// hook if it takes to long to process.  If you need to do any extended
// processing, please do so by copying the event to your own queued dispatch
// thread.
void dispatch_proc(uiohook_event *const event) {
    switch (event->type) {
    case EVENT_KEY_PRESSED:
    case EVENT_KEY_RELEASED:
    case EVENT_KEY_TYPED:
        if (current_mode == XHookMode::KEYBOARD || current_mode == XHookMode::MOUSE_AND_KEYBOARD) {

            // Ensure that we are not messing with some other hook, just in case
            //			if (Engine::Timer::getInstance()->getHook()->getType()
            //== 					Engine::Hook::HookType::X_KEYBOARD || 				Engine::Timer::getInstance()->getHook()->getType()
            //== 					Engine::Hook::HookType::X_MOUSE_KEYBOARD) {

            //				Engine::Timer::getInstance()->getHook().get()->setState(
            //					Engine::Hook::HookState::productive);
            //			} else {
            //				// This should never happen.
            //			}
        }
        break;
    case EVENT_MOUSE_PRESSED:
    case EVENT_MOUSE_RELEASED:
    case EVENT_MOUSE_CLICKED:
    case EVENT_MOUSE_MOVED:
    case EVENT_MOUSE_DRAGGED:
    case EVENT_MOUSE_WHEEL:
        if (current_mode == XHookMode::MOUSE || current_mode == XHookMode::MOUSE_AND_KEYBOARD) {

            // Ensure that we are not messing with some other hook, just in case
            //            if (Engine::Timer::getInstance()->getHook()->getType() ==
            //                    Engine::Hook::HookType::X_MOUSE ||
            //                Engine::Timer::getInstance()->getHook()->getType() ==
            //                    Engine::Hook::HookType::X_MOUSE_KEYBOARD) {

            //                Engine::Timer::getInstance()->getHook().get()->setState(
            //                    Engine::Hook::HookState::productive);
            //            } else {
            //                // This should never happen.
            //            }
        }
        break;
    default:
        break;
    }
}

int Engine::run_xhook_engine(XHookMode mode) {
    // We need to disable buffering in order for this process to send the
    // "readyReadStandardOutput" signal to Tasker
    setbuf(stdout, NULL);

    current_mode = mode;

    // Set the logger callback for library output.
    hook_set_logger_proc(&logger_proc);

    // Set the event callback for uiohook events.
    hook_set_dispatch_proc(&dispatch_proc);

    // Start the hook and block.
    // NOTE If EVENT_HOOK_ENABLED was delivered, the status will always succeed.
    int status = hook_run();
    switch (status) {
    case UIOHOOK_SUCCESS:
        // Everything is ok.
        {
            printf("UIOHOOK_SUCCESS\n");
            break;
        }

    // System level errors.
    case UIOHOOK_ERROR_OUT_OF_MEMORY:
        logger_proc(LOG_LEVEL_ERROR, "Failed to allocate memory. (%#X)", status);
        break;

    // X11 specific errors.
    case UIOHOOK_ERROR_X_OPEN_DISPLAY:
        logger_proc(LOG_LEVEL_ERROR, "Failed to open X11 display. (%#X)", status);
        break;

    case UIOHOOK_ERROR_X_RECORD_NOT_FOUND:
        logger_proc(LOG_LEVEL_ERROR, "Unable to locate XRecord extension. (%#X)", status);
        break;

    case UIOHOOK_ERROR_X_RECORD_ALLOC_RANGE:
        logger_proc(LOG_LEVEL_ERROR, "Unable to allocate XRecord range. (%#X)", status);
        break;

    case UIOHOOK_ERROR_X_RECORD_CREATE_CONTEXT:
        logger_proc(LOG_LEVEL_ERROR, "Unable to allocate XRecord context. (%#X)", status);
        break;

    case UIOHOOK_ERROR_X_RECORD_ENABLE_CONTEXT:
        logger_proc(LOG_LEVEL_ERROR, "Failed to enable XRecord context. (%#X)", status);
        break;

    // Windows specific errors.
    case UIOHOOK_ERROR_SET_WINDOWS_HOOK_EX:
        logger_proc(LOG_LEVEL_ERROR,
                    "Failed to register low level windows hook. (%#X)", status);
        break;

    // Darwin specific errors.
    case UIOHOOK_ERROR_AXAPI_DISABLED:
        logger_proc(LOG_LEVEL_ERROR,
                    "Failed to enable access for assistive devices. (%#X)", status);
        break;

    case UIOHOOK_ERROR_CREATE_EVENT_PORT:
        logger_proc(LOG_LEVEL_ERROR, "Failed to create apple event port. (%#X)", status);
        break;

    case UIOHOOK_ERROR_CREATE_RUN_LOOP_SOURCE:
        logger_proc(LOG_LEVEL_ERROR, "Failed to create apple run loop source. (%#X)", status);
        break;

    case UIOHOOK_ERROR_GET_RUNLOOP:
        logger_proc(LOG_LEVEL_ERROR, "Failed to acquire apple run loop. (%#X)", status);
        break;

    case UIOHOOK_ERROR_CREATE_OBSERVER:
        logger_proc(LOG_LEVEL_ERROR,
                    "Failed to create apple run loop observer. (%#X)", status);
        break;

    // Default error.
    case UIOHOOK_FAILURE:
    default:
        logger_proc(LOG_LEVEL_ERROR, "An unknown hook error occurred. (%#X)", status);
        break;
    }

    return status;
}

/**
 * @brief XHook::XHook initializes this Xhook instance with the specified
 * XhookMode. It hooks all signals necessary to do IPC with the external Xhook
 * child process.
 * @param newXMode The mode(mouse, keyboard or both) this instance will be on.
 */
XHook::XHook(Engine::XHookMode newXMode) {
    XMode = newXMode;
}
/**
 * @brief XHook::XHook initializes this Xhook instance on keyboard_and_mouse
 * mode. It hooks all signals necessary to do IPC with the external Xhook child
 * process.
 * @param newXMode The mode(mouse, keyboard or both) this instance will be on.
 */
XHook::XHook() {
    XMode = XHookMode::MOUSE_AND_KEYBOARD;
}
/**
 * @brief XHook::start
 */
void XHook::start() {
    startXHook();
}

/**
 * @brief XHook::end kills the keyboard/mouse hook.
 */
void XHook::end() {
    hook_stop();
}

/**
 * @brief XHook::pause Does nothing.
 */
void XHook::pause() {
}

/**
 * @brief  XHook::update
 *
 */
void XHook::update() {
}

/**
 * @brief XHook::startHook
 * @return
 */
Hook::HookState XHook::startHook() {
    return getState();
}
void XHook::resetState() {
    setState(HookState::unproductive);
}

/**
 * @brief XListener::startXHook
 * Spawn process which is a hardware hook for mouse, keyboard or both
 * @return 0 on success. Error codes to be implemented.
 */
int XHook::startXHook() {
    setState(HookState::unproductive);

    int ret = run_xhook_engine(XMode);

    printf("ret code for run_xhook_engine:%d\n", ret);

    return 0;
}
void XHook::setState(HookState newState) {
    Hook::setState(newState);
}
/**
 * @brief Engine::Engine::Hook::getState
 *        Returns current state of the Hook, unproductive or productive
 *
 * @return Engine::Engine::Hook::HookState::unproductive,
 *         or
 *         Engine::Engine::Hook::Engine::Hook::productive
 */
Hook::HookState XHook::getState() {
    return state;
}
void XHook::setMode(Engine::XHookMode newMode) {
    // TODO: Check state(?)
    XMode = newMode;
}
