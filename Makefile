include make.config

.PHONY: all
all: $(TARGET)

.PHONY: run
run: $(TARGET)
	@./$(BUILDDIR)/$(TARGET)

%.o: %.s
	@echo -e "$(C_GREEN)$(S_BOLD)[ AS $< -o $@ ]$(S_CLEAR)$(C_CLEAR)"
	@$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	@echo -e "$(C_GREEN)$(S_BOLD)[ CC $< -o $@ ]$(S_CLEAR)$(C_CLEAR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.o: %.cpp
	@echo -e "$(C_GREEN)$(S_BOLD)[ CXX $< -o $@ ]$(S_CLEAR)$(C_CLEAR)"
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(TARGET): $(OBJ) $(BUILDDIR)
	@echo -e "$(C_GREEN)$(S_BOLD)[ LD objs -o $(TARGET) ]$(S_CLEAR)$(C_CLEAR)"
	@$(LD) $(LDFLAGS) $(LIBS) -o $(BUILDDIR)/$(TARGET) $(OBJ)


.PHONY: clean
clean:
	@rm -rf $(OBJ) $(BUILDDIR)
