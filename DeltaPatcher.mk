##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=DeltaPatcher
ConfigurationName      :=Release
WorkspacePath          := "C:\Users\Marco\Documents\CodeLite\workspace"
ProjectPath            := "C:\Users\Marco\Documents\CodeLite\workspace\DeltaPatcher"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Marco
Date                   :=06/12/15
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./Release/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="DeltaPatcher.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=windres
LinkOptions            :=  -s -static-libgcc -mwindows $(shell wx-config --debug=no --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)./3rdparty $(IncludeSwitch)./src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
CFLAGS   :=  -O2 $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
WXWIN:=C:\wxWidgets-3.0.2
PATH:=$(WXWIN)\lib\gcc_lib;$(PATH)
WXCFG:=gcc_lib\mswu
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_DPApp$(ObjectSuffix) $(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix) $(IntermediateDirectory)/gui_dpgui$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix) $(IntermediateDirectory)/utils_base64$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_DPApp$(ObjectSuffix): src/DPApp.cpp $(IntermediateDirectory)/src_DPApp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/DPApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DPApp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DPApp$(DependSuffix): src/DPApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DPApp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DPApp$(DependSuffix) -MM "src/DPApp.cpp"

$(IntermediateDirectory)/src_DPApp$(PreprocessSuffix): src/DPApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DPApp$(PreprocessSuffix) "src/DPApp.cpp"

$(IntermediateDirectory)/resource.rc$(ObjectSuffix): resource.rc
	$(RcCompilerName) -i "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix): src/patcher/XDeltaPatch.cpp $(IntermediateDirectory)/patcher_XDeltaPatch$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/patcher/XDeltaPatch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/patcher_XDeltaPatch$(DependSuffix): src/patcher/XDeltaPatch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix) -MF$(IntermediateDirectory)/patcher_XDeltaPatch$(DependSuffix) -MM "src/patcher/XDeltaPatch.cpp"

$(IntermediateDirectory)/patcher_XDeltaPatch$(PreprocessSuffix): src/patcher/XDeltaPatch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/patcher_XDeltaPatch$(PreprocessSuffix) "src/patcher/XDeltaPatch.cpp"

$(IntermediateDirectory)/gui_dpgui$(ObjectSuffix): src/gui/dpgui.cpp $(IntermediateDirectory)/gui_dpgui$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/dpgui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_dpgui$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_dpgui$(DependSuffix): src/gui/dpgui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_dpgui$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_dpgui$(DependSuffix) -MM "src/gui/dpgui.cpp"

$(IntermediateDirectory)/gui_dpgui$(PreprocessSuffix): src/gui/dpgui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_dpgui$(PreprocessSuffix) "src/gui/dpgui.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix): src/gui/DeltaPatcherDecodePanel.cpp $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherDecodePanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(DependSuffix): src/gui/DeltaPatcherDecodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(DependSuffix) -MM "src/gui/DeltaPatcherDecodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(PreprocessSuffix): src/gui/DeltaPatcherDecodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(PreprocessSuffix) "src/gui/DeltaPatcherDecodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix): src/gui/DeltaPatcherMainDialog.cpp $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherMainDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(DependSuffix): src/gui/DeltaPatcherMainDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(DependSuffix) -MM "src/gui/DeltaPatcherMainDialog.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(PreprocessSuffix): src/gui/DeltaPatcherMainDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(PreprocessSuffix) "src/gui/DeltaPatcherMainDialog.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix): src/gui/DeltaPatcherEncodePanel.cpp $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherEncodePanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(DependSuffix): src/gui/DeltaPatcherEncodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(DependSuffix) -MM "src/gui/DeltaPatcherEncodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(PreprocessSuffix): src/gui/DeltaPatcherEncodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(PreprocessSuffix) "src/gui/DeltaPatcherEncodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix): src/gui/DeltaPatcherDropTarget.cpp $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherDropTarget.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(DependSuffix): src/gui/DeltaPatcherDropTarget.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(DependSuffix) -MM "src/gui/DeltaPatcherDropTarget.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(PreprocessSuffix): src/gui/DeltaPatcherDropTarget.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(PreprocessSuffix) "src/gui/DeltaPatcherDropTarget.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix): src/gui/DeltaPatcherAboutDialog.cpp $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherAboutDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(DependSuffix): src/gui/DeltaPatcherAboutDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(DependSuffix) -MM "src/gui/DeltaPatcherAboutDialog.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(PreprocessSuffix): src/gui/DeltaPatcherAboutDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(PreprocessSuffix) "src/gui/DeltaPatcherAboutDialog.cpp"

$(IntermediateDirectory)/utils_base64$(ObjectSuffix): src/utils/base64.cpp $(IntermediateDirectory)/utils_base64$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/utils/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_base64$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_base64$(DependSuffix): src/utils/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_base64$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_base64$(DependSuffix) -MM "src/utils/base64.cpp"

$(IntermediateDirectory)/utils_base64$(PreprocessSuffix): src/utils/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_base64$(PreprocessSuffix) "src/utils/base64.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_DPApp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_DPApp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_DPApp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource.rc$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/patcher_XDeltaPatch$(DependSuffix)
	$(RM) $(IntermediateDirectory)/patcher_XDeltaPatch$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_dpgui$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_dpgui$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_dpgui$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utils_base64$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utils_base64$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utils_base64$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/DeltaPatcher"


