GPIO LED Blink:

Using this command
st-flash write app.bin 0x8000000
It writes to the 0x8000000 address

LOGS:
st-flash 1.7.0
2025-12-06T23:38:53 INFO common.c: F1xx High-density: 64 KiB SRAM, 256 KiB flash in at least 2 KiB pages.
file app.bin md5 checksum: c8435594495c76246fec2dd75ca7288, stlink checksum: 0x0002984d
2025-12-06T23:38:53 INFO common.c: Attempting to write 3096 (0xc18) bytes to stm32 address: 134217728 (0x8000000)
2025-12-06T23:38:53 INFO common.c: Flash page at addr: 0x08000000 erased
2025-12-06T23:38:53 INFO common.c: Flash page at addr: 0x08000800 erased
2025-12-06T23:38:53 INFO common.c: Finished erasing 2 pages of 2048 (0x800) bytes
2025-12-06T23:38:53 INFO common.c: Starting Flash write for VL/F0/F3/F1_XL
2025-12-06T23:38:53 INFO flash_loader.c: Successfully loaded flash loader in sram
2025-12-06T23:38:53 INFO flash_loader.c: Clear DFSR
  2/  2 pages written
2025-12-06T23:38:53 INFO common.c: Starting verification of write complete
2025-12-06T23:38:53 INFO common.c: Flash written and verified! jolly good!
**** This log says my MCU has 64 KiB SRAM, 256 KiB flash in at least 2 KiB pages
**** My application erases two pages of size 2KB to write 3096 bytes

git remote add origin https://github.com/username/repo.git
git push -u origin master




