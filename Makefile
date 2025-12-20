#============Directories=====================
MDFP ="/opt/microchip/mplabx/v6.25/packs/Microchip/PIC18Fxxxx_DFP/1.7.171/xc8"
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin
INCLUDE_DIRS = inc

#===========TOOLACHAIN=====================
CC = xc8-cc
RM = rm
    
#===========FILES=======================
TARGET = $(BIN_DIR)/button
    
SOURCES = main.c\
		src/button.c\
		src/gpio.c
		 
           
    
OBJECT_NAMES = $(SOURCES:.c=.p1)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(OBJECT_NAMES))
     
#===========FLAGS========================
MCU = 18F4550
WFLAGS = -WCL4 -Wextra -Werror -Wshadow
OPT = -O1
CFLAGS = -mcpu=$(MCU) $(WFLAGS) -mdfp=$(MDFP) $(OPT) -I $(INCLUDE_DIRS)
LDFLAGS = -mcpu=$(MCU) -mdfp=$(MDFP) -I $(INCLUDE_DIRS)
    
#==========FLASH FLAGS==================
DEVICE = -ppic18f4550
PK2 = pk2cmd
    
#Build
##Linking
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC)  $(LDFLAGS) $^ -o $@
    
##Compiling   
$(OBJ_DIR)/%.p1: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^
#Phonies
.PHONY: all clean flash
all: $(TARGET)

clean:
	$(RM) -r $(BUILD_DIR)
   
flash:  
	$(PK2) $(DEVICE) -f$(TARGET).hex -m -P -R -J 

