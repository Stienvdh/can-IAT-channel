include ../Makefile.include

SOURCES         = $(shell ls *.c)
OBJECTS         = $(SOURCES:.c=.o)
FPGA_DEV = /dev/ttyUSB0

TARGET          = main.elf
TARGET_NO_WRAP  = no_wrap_$(TARGET)

VULCAN_DIR      = ..
CFLAGS         += -I$(VULCAN_DIR)

all: $(TARGET)

$(TARGET_NO_WRAP): $(OBJECTS)
	$(LD) $(LDFLAGS) --prepare-for-sm-text-section-wrapping -o $@ $^

$(TARGET): $(TARGET_NO_WRAP)
	$(SANCUS_CRYPTO) --wrap-sm-text-sections $(CRYPTOFLAGS) -o $@ $<

load: $(TARGET)
	$(SANCUS_LOAD) $(LOADFLAGS) $<

load_with_noise: $(TARGET)
	$(SANCUS_LOAD) $(LOADFLAGS) $<
	canplayer -I ../../../CAN-traffic/20170410-can-data/skoda.dump

sim: $(TARGET)
	$(SANCUS_SIM) $(SIMFLAGS) $<

clean:
	$(RM) $(TARGET) $(TARGET_NO_MAC) $(OBJECTS)
	rm -f sim-input.bin sim-output.bin
	rm -f *.fst *.vcd
