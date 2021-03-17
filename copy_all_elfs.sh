#Script for copying all elfs to destination
ldd file | grep "=> /" | awk '{print $3}' | xargs -I '{}' cp -v '{}' /destination
