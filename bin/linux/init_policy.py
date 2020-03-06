#!/usr/bin/env python3
"""
This script sets up the sudo policy for Tasker on linux.
If you have an Ubuntu-based distro, this should go smoothly.
The script has been tested on Linux Mint 19.2 Cinnamon
"""
from os import path
import subprocess
import xml.etree.ElementTree as ET
xml_file_header = open(".xml_policy_header", mode="r+b").read()
xml_file = open("com.tasker.tasker.policy", mode="a+b")
xml_file.truncate(0)
xml_file.write(xml_file_header)



tasker_absolute_path  = path.abspath("Tasker")
tree =  ET.parse("com.tasker.tasker.policy_for_script")

tree_root = tree.getroot()
element = tree_root.find('action')
annotations =  element.findall('annotate')

for child in annotations:
    if(child.attrib['key'] == "org.freedesktop.policykit.exec.path"):
        child.text = tasker_absolute_path

tree.write(xml_file)


subprocess.run(["sudo", "cp", "com.tasker.tasker.policy", "/usr/share/polkit-1/actions"])
