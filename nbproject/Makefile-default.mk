#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=circular_buffer_library.c lcd_library.c plotter_library.c plotter_main.c plotter_utils.c joystick_library.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/circular_buffer_library.o ${OBJECTDIR}/lcd_library.o ${OBJECTDIR}/plotter_library.o ${OBJECTDIR}/plotter_main.o ${OBJECTDIR}/plotter_utils.o ${OBJECTDIR}/joystick_library.o
POSSIBLE_DEPFILES=${OBJECTDIR}/circular_buffer_library.o.d ${OBJECTDIR}/lcd_library.o.d ${OBJECTDIR}/plotter_library.o.d ${OBJECTDIR}/plotter_main.o.d ${OBJECTDIR}/plotter_utils.o.d ${OBJECTDIR}/joystick_library.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/circular_buffer_library.o ${OBJECTDIR}/lcd_library.o ${OBJECTDIR}/plotter_library.o ${OBJECTDIR}/plotter_main.o ${OBJECTDIR}/plotter_utils.o ${OBJECTDIR}/joystick_library.o

# Source Files
SOURCEFILES=circular_buffer_library.c lcd_library.c plotter_library.c plotter_main.c plotter_utils.c joystick_library.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/circular_buffer_library.o: circular_buffer_library.c  .generated_files/flags/default/3d641be7e9952f7ea2930cb006a0746d7e89478 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/circular_buffer_library.o.d 
	@${RM} ${OBJECTDIR}/circular_buffer_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  circular_buffer_library.c  -o ${OBJECTDIR}/circular_buffer_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/circular_buffer_library.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/lcd_library.o: lcd_library.c  .generated_files/flags/default/662efddb4578055f16b94fd9712a48f0e0620ea2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_library.o.d 
	@${RM} ${OBJECTDIR}/lcd_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd_library.c  -o ${OBJECTDIR}/lcd_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd_library.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/plotter_library.o: plotter_library.c  .generated_files/flags/default/f1509912277d0bd43e7e049f3645dac102032187 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/plotter_library.o.d 
	@${RM} ${OBJECTDIR}/plotter_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  plotter_library.c  -o ${OBJECTDIR}/plotter_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/plotter_library.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/plotter_main.o: plotter_main.c  .generated_files/flags/default/e4fc0e08f312d3ed084ff2554a19ff3b2a1200f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/plotter_main.o.d 
	@${RM} ${OBJECTDIR}/plotter_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  plotter_main.c  -o ${OBJECTDIR}/plotter_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/plotter_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/plotter_utils.o: plotter_utils.c  .generated_files/flags/default/cb36209e1c5703564d495ca0032caeace0b2478f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/plotter_utils.o.d 
	@${RM} ${OBJECTDIR}/plotter_utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  plotter_utils.c  -o ${OBJECTDIR}/plotter_utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/plotter_utils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/joystick_library.o: joystick_library.c  .generated_files/flags/default/120085a03d7696ae83dbd609bf766ebe50a798fa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/joystick_library.o.d 
	@${RM} ${OBJECTDIR}/joystick_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  joystick_library.c  -o ${OBJECTDIR}/joystick_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/joystick_library.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/circular_buffer_library.o: circular_buffer_library.c  .generated_files/flags/default/a8fe05dbd0f7d33c47f329fc0c9b011675f7219 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/circular_buffer_library.o.d 
	@${RM} ${OBJECTDIR}/circular_buffer_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  circular_buffer_library.c  -o ${OBJECTDIR}/circular_buffer_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/circular_buffer_library.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/lcd_library.o: lcd_library.c  .generated_files/flags/default/a44912bc73747ab5dcf04dc6df489d67f8ac4f0b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_library.o.d 
	@${RM} ${OBJECTDIR}/lcd_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd_library.c  -o ${OBJECTDIR}/lcd_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd_library.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/plotter_library.o: plotter_library.c  .generated_files/flags/default/d495a5597e3e3445f2bd96fcaa67de841cb286db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/plotter_library.o.d 
	@${RM} ${OBJECTDIR}/plotter_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  plotter_library.c  -o ${OBJECTDIR}/plotter_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/plotter_library.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/plotter_main.o: plotter_main.c  .generated_files/flags/default/5d36b4bfe9fc65cfc84e58d52da5483de7d0e075 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/plotter_main.o.d 
	@${RM} ${OBJECTDIR}/plotter_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  plotter_main.c  -o ${OBJECTDIR}/plotter_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/plotter_main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/plotter_utils.o: plotter_utils.c  .generated_files/flags/default/e2b753c238ecd318e696929c5ee236208c9e1e6a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/plotter_utils.o.d 
	@${RM} ${OBJECTDIR}/plotter_utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  plotter_utils.c  -o ${OBJECTDIR}/plotter_utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/plotter_utils.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/joystick_library.o: joystick_library.c  .generated_files/flags/default/a45400fec5e64418a0ccce6a3ca686a8b4eb8be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/joystick_library.o.d 
	@${RM} ${OBJECTDIR}/joystick_library.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  joystick_library.c  -o ${OBJECTDIR}/joystick_library.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/joystick_library.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
