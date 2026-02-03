TARGET = app
CC = arm-none-eabi-gcc
OBJCOPY  = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m3 -mthumb -O0 -g -Iinc
LDSCRIPT = STM32F103C8TX_FLASH.ld 
LDFLAGS = -T$(LDSCRIPT) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map

SRC_DIR=src
INC_DIR=inc
BUILD_DIR=build


C_SRCS = $(wildcard $(SRC_DIR)/*.c)
S_SRCS = $(wildcard $(SRC_DIR)/*.s)

SRCS = $(C_SRCS) $(S_SRCS)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS := $(OBJS:$(SRC_DIR)/%.s=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@
clean:
	rm -rf $(BUILD_DIR)

.PHONY:all clean

