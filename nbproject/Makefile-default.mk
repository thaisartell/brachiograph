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
SOURCEFILES_QUOTED_IF_SPACED=troth004_lcd_library_v1.c troth004_plotter_library_v1.c troth004_project_troubleshooting_v3.c troth004_circular_buffer_library_v1.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/troth004_lcd_library_v1.o ${OBJECTDIR}/troth004_plotter_library_v1.o ${OBJECTDIR}/troth004_project_troubleshooting_v3.o ${OBJECTDIR}/troth004_circular_buffer_library_v1.o
POSSIBLE_DEPFILES=${OBJECTDIR}/troth004_lcd_library_v1.o.d ${OBJECTDIR}/troth004_plotter_library_v1.o.d ${OBJECTDIR}/troth004_project_troubleshooting_v3.o.d ${OBJECTDIR}/troth004_circular_buffer_library_v1.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/troth004_lcd_library_v1.o ${OBJECTDIR}/troth004_plotter_library_v1.o ${OBJECTDIR}/troth004_project_troubleshooting_v3.o ${OBJECTDIR}/troth004_circular_buffer_library_v1.o

# Source Files
SOURCEFILES=troth004_lcd_library_v1.c troth004_plotter_library_v1.c troth004_project_troubleshooting_v3.c troth004_circular_buffer_library_v1.c



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
${OBJECTDIR}/troth004_lcd_library_v1.o: troth004_lcd_library_v1.c  .generated_files/flags/default/3d4c9dec6760a7fab29db4f7c653a8c781600ca4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_lcd_library_v1.o.d 
	@${RM} ${OBJECTDIR}/troth004_lcd_library_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_lcd_library_v1.c  -o ${OBJECTDIR}/troth004_lcd_library_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_lcd_library_v1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/troth004_plotter_library_v1.o: troth004_plotter_library_v1.c  .generated_files/flags/default/7dc14f4640f57df86586910d99b35cb5bfe20c58 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_plotter_library_v1.o.d 
	@${RM} ${OBJECTDIR}/troth004_plotter_library_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_plotter_library_v1.c  -o ${OBJECTDIR}/troth004_plotter_library_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_plotter_library_v1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/troth004_project_troubleshooting_v3.o: troth004_project_troubleshooting_v3.c  .generated_files/flags/default/a39a703860f4b5eb4e68166a607d41456429b933 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_project_troubleshooting_v3.o.d 
	@${RM} ${OBJECTDIR}/troth004_project_troubleshooting_v3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_project_troubleshooting_v3.c  -o ${OBJECTDIR}/troth004_project_troubleshooting_v3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_project_troubleshooting_v3.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/troth004_circular_buffer_library_v1.o: troth004_circular_buffer_library_v1.c  .generated_files/flags/default/1c316ca7dd7d54a96077357a8642589597cf4962 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_circular_buffer_library_v1.o.d 
	@${RM} ${OBJECTDIR}/troth004_circular_buffer_library_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_circular_buffer_library_v1.c  -o ${OBJECTDIR}/troth004_circular_buffer_library_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_circular_buffer_library_v1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/troth004_lcd_library_v1.o: troth004_lcd_library_v1.c  .generated_files/flags/default/ff564d2aba93958b5872c43c5bbc59e0485fc8d6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_lcd_library_v1.o.d 
	@${RM} ${OBJECTDIR}/troth004_lcd_library_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_lcd_library_v1.c  -o ${OBJECTDIR}/troth004_lcd_library_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_lcd_library_v1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/troth004_plotter_library_v1.o: troth004_plotter_library_v1.c  .generated_files/flags/default/59ca5be015bbb5280e6454597252639f3c6cef7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_plotter_library_v1.o.d 
	@${RM} ${OBJECTDIR}/troth004_plotter_library_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_plotter_library_v1.c  -o ${OBJECTDIR}/troth004_plotter_library_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_plotter_library_v1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/troth004_project_troubleshooting_v3.o: troth004_project_troubleshooting_v3.c  .generated_files/flags/default/38dc2fc41c56c66c63620360c3dbeda94b8a6185 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_project_troubleshooting_v3.o.d 
	@${RM} ${OBJECTDIR}/troth004_project_troubleshooting_v3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_project_troubleshooting_v3.c  -o ${OBJECTDIR}/troth004_project_troubleshooting_v3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_project_troubleshooting_v3.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/troth004_circular_buffer_library_v1.o: troth004_circular_buffer_library_v1.c  .generated_files/flags/default/30e508944a2c07841821491c751bf37be89a5701 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/troth004_circular_buffer_library_v1.o.d 
	@${RM} ${OBJECTDIR}/troth004_circular_buffer_library_v1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  troth004_circular_buffer_library_v1.c  -o ${OBJECTDIR}/troth004_circular_buffer_library_v1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/troth004_circular_buffer_library_v1.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/brachiograph.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/brachiograph.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
