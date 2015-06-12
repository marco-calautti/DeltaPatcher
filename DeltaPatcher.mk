##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## ReleaseUnix
ProjectName            :=DeltaPatcher
ConfigurationName      :=ReleaseUnix
WorkspacePath          := "/home/marco/.codelite/workspace"
ProjectPath            := "/home/marco/.codelite/workspace/DeltaPatcher"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Marco
Date                   :=06/12/15
CodeLitePath           :="/home/marco/.codelite"
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
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -s -static-libgcc $(shell wx-config --debug=no --libs --unicode=yes)
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
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_DPApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_dpgui.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/utils_base64.cpp$(ObjectSuffix) 



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
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_DPApp.cpp$(ObjectSuffix): src/DPApp.cpp $(IntermediateDirectory)/src_DPApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/DPApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DPApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DPApp.cpp$(DependSuffix): src/DPApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DPApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DPApp.cpp$(DependSuffix) -MM "src/DPApp.cpp"

$(IntermediateDirectory)/src_DPApp.cpp$(PreprocessSuffix): src/DPApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DPApp.cpp$(PreprocessSuffix) "src/DPApp.cpp"

$(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(ObjectSuffix): src/patcher/XDeltaPatch.cpp $(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/patcher/XDeltaPatch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(DependSuffix): src/patcher/XDeltaPatch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(DependSuffix) -MM "src/patcher/XDeltaPatch.cpp"

$(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(PreprocessSuffix): src/patcher/XDeltaPatch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/patcher_XDeltaPatch.cpp$(PreprocessSuffix) "src/patcher/XDeltaPatch.cpp"

$(IntermediateDirectory)/gui_dpgui.cpp$(ObjectSuffix): src/gui/dpgui.cpp $(IntermediateDirectory)/gui_dpgui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/gui/dpgui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_dpgui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_dpgui.cpp$(DependSuffix): src/gui/dpgui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_dpgui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_dpgui.cpp$(DependSuffix) -MM "src/gui/dpgui.cpp"

$(IntermediateDirectory)/gui_dpgui.cpp$(PreprocessSuffix): src/gui/dpgui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_dpgui.cpp$(PreprocessSuffix) "src/gui/dpgui.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(ObjectSuffix): src/gui/DeltaPatcherDecodePanel.cpp $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/gui/DeltaPatcherDecodePanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(DependSuffix): src/gui/DeltaPatcherDecodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(DependSuffix) -MM "src/gui/DeltaPatcherDecodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(PreprocessSuffix): src/gui/DeltaPatcherDecodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel.cpp$(PreprocessSuffix) "src/gui/DeltaPatcherDecodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(ObjectSuffix): src/gui/DeltaPatcherMainDialog.cpp $(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/gui/DeltaPatcherMainDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(DependSuffix): src/gui/DeltaPatcherMainDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(DependSuffix) -MM "src/gui/DeltaPatcherMainDialog.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(PreprocessSuffix): src/gui/DeltaPatcherMainDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog.cpp$(PreprocessSuffix) "src/gui/DeltaPatcherMainDialog.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(ObjectSuffix): src/gui/DeltaPatcherEncodePanel.cpp $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/gui/DeltaPatcherEncodePanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(DependSuffix): src/gui/DeltaPatcherEncodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(DependSuffix) -MM "src/gui/DeltaPatcherEncodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(PreprocessSuffix): src/gui/DeltaPatcherEncodePanel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel.cpp$(PreprocessSuffix) "src/gui/DeltaPatcherEncodePanel.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(ObjectSuffix): src/gui/DeltaPatcherDropTarget.cpp $(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/gui/DeltaPatcherDropTarget.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(DependSuffix): src/gui/DeltaPatcherDropTarget.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(DependSuffix) -MM "src/gui/DeltaPatcherDropTarget.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(PreprocessSuffix): src/gui/DeltaPatcherDropTarget.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget.cpp$(PreprocessSuffix) "src/gui/DeltaPatcherDropTarget.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(ObjectSuffix): src/gui/DeltaPatcherAboutDialog.cpp $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/gui/DeltaPatcherAboutDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(DependSuffix): src/gui/DeltaPatcherAboutDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(DependSuffix) -MM "src/gui/DeltaPatcherAboutDialog.cpp"

$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(PreprocessSuffix): src/gui/DeltaPatcherAboutDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog.cpp$(PreprocessSuffix) "src/gui/DeltaPatcherAboutDialog.cpp"

$(IntermediateDirectory)/utils_base64.cpp$(ObjectSuffix): src/utils/base64.cpp $(IntermediateDirectory)/utils_base64.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/marco/.codelite/workspace/DeltaPatcher/src/utils/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_base64.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_base64.cpp$(DependSuffix): src/utils/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_base64.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_base64.cpp$(DependSuffix) -MM "src/utils/base64.cpp"

$(IntermediateDirectory)/utils_base64.cpp$(PreprocessSuffix): src/utils/base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_base64.cpp$(PreprocessSuffix) "src/utils/base64.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


