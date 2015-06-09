##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DeltaPatcher
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Marco\Documents\CodeLite\workspace"
ProjectPath            := "C:\Users\Marco\Documents\CodeLite\workspace\DeltaPatcher"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Marco
Date                   :=06/09/15
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=link.exe  /nologo
SharedObjectLinkerName :=link.exe /DLL  /nologo
ObjectSuffix           :=.obj
DependSuffix           :=
PreprocessSuffix       :=
DebugSwitch            :=/Zi 
IncludeSwitch          :=/I
LibrarySwitch          := 
OutputSwitch           :=/OUT:
LibraryPathSwitch      :=/LIBPATH:
PreprocessorSwitch     :=/D
SourceSwitch           :=
OutputFile             :=./workingdir/dpD.exe
Preprocessors          :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch           :=/Fo
ArchiveOutputSwitch    :=/OUT:
PreprocessOnlySwitch   :=
ObjectsFileList        :="DeltaPatcher.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=windres
LinkOptions            :=  -mwindows $(shell wx-config --debug=yes --libs --unicode=yes)
IncludePath            := $(IncludeSwitch)""C:/Program Files/Microsoft Visual Studio 8/VC/include"" $(IncludeSwitch).  $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)./3rdparty $(IncludeSwitch)./src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)""C:/Program Files/Microsoft Visual Studio 8/VC/lib""  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := lib.exe  /nologo
CXX      := cl.exe /nologo /c
CC       := cl.exe /nologo /c
CXXFLAGS :=  -g $(shell wx-config --cxxflags --unicode=yes --debug=yes) $(Preprocessors)
CFLAGS   :=  -g $(shell wx-config --cxxflags --unicode=yes --debug=yes) $(Preprocessors)
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
Objects0=$(IntermediateDirectory)/src_DPApp$(ObjectSuffix) $(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix) $(IntermediateDirectory)/gui_dpgui$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix) $(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_DPApp$(ObjectSuffix): src/DPApp.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/DPApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DPApp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resource.rc$(ObjectSuffix): resource.rc
	$(RcCompilerName) -i "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix): src/patcher/XDeltaPatch.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/patcher/XDeltaPatch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/patcher_XDeltaPatch$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_dpgui$(ObjectSuffix): src/gui/dpgui.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/dpgui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_dpgui$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix): src/gui/DeltaPatcherDecodePanel.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherDecodePanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherDecodePanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix): src/gui/DeltaPatcherMainDialog.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherMainDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherMainDialog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix): src/gui/DeltaPatcherEncodePanel.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherEncodePanel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherEncodePanel$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix): src/gui/DeltaPatcherDropTarget.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherDropTarget.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherDropTarget$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix): src/gui/DeltaPatcherAboutDialog.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Marco/Documents/CodeLite/workspace/DeltaPatcher/src/gui/DeltaPatcherAboutDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_DeltaPatcherAboutDialog$(ObjectSuffix) $(IncludePath)
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
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/DeltaPatcher"


