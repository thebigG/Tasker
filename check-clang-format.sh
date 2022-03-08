#!/usr/bin/env bash
clang-format --dry-run --Werror -style=file Tasker/*
exit $?
