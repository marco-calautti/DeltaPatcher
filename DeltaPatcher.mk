##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=DeltaPatcher
ConfigurationName      :=Release
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "D:\Documenti\CodeLite Projects\workspace"
ProjectPath            := "D:\Documenti\CodeLite Projects\workspace\DeltaPatcher"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=08/25/10
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=./workingdir/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=
MakeDirCommand         :=makedir
CmpOptions             := -O2 $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=windres
LinkOptions            :=  -s -static-libgcc -mwindows $(shell wx-config --debug=no --libs --unicode=yes)
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)./include" "$(IncludeSwitch)./3rdparty" "$(IncludeSwitch)./src" 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXCFG:=gcc_lib\mswu
WXWIN:=C:\wxWidgets-2.8.9
Objects=src/$(IntermediateDirectory)/DPApp$(ObjectSuffix) src/patcher/$(IntermediateDirectory)/XDeltaPatch$(ObjectSuffix) src/gui/$(IntermediateDirectory)/dpgui$(ObjectSuffix) src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(ObjectSuffix) src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(ObjectSuffix) src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(ObjectSuffix) src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(ObjectSuffix) src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(ObjectSuffix) $(IntermediateDirectory)/resource.rc$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
src/$(IntermediateDirectory)/DPApp$(ObjectSuffix): src/DPApp.cpp src/$(IntermediateDirectory)/DPApp$(DependSuffix)
	@$(MakeDirCommand) "src/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/DPApp.cpp" $(CmpOptions) $(ObjectSwitch)src/$(IntermediateDirectory)/DPApp$(ObjectSuffix) $(IncludePath)
src/$(IntermediateDirectory)/DPApp$(DependSuffix): src/DPApp.cpp
	@$(MakeDirCommand) "src/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/$(IntermediateDirectory)/DPApp$(ObjectSuffix) -MFsrc/$(IntermediateDirectory)/DPApp$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/DPApp.cpp"

src/patcher/$(IntermediateDirectory)/XDeltaPatch$(ObjectSuffix): src/patcher/XDeltaPatch.cpp src/patcher/$(IntermediateDirectory)/XDeltaPatch$(DependSuffix)
	@$(MakeDirCommand) "src/patcher/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/patcher/XDeltaPatch.cpp" $(CmpOptions) $(ObjectSwitch)src/patcher/$(IntermediateDirectory)/XDeltaPatch$(ObjectSuffix) $(IncludePath)
src/patcher/$(IntermediateDirectory)/XDeltaPatch$(DependSuffix): src/patcher/XDeltaPatch.cpp
	@$(MakeDirCommand) "src/patcher/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/patcher/$(IntermediateDirectory)/XDeltaPatch$(ObjectSuffix) -MFsrc/patcher/$(IntermediateDirectory)/XDeltaPatch$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/patcher/XDeltaPatch.cpp"

src/gui/$(IntermediateDirectory)/dpgui$(ObjectSuffix): src/gui/dpgui.cpp src/gui/$(IntermediateDirectory)/dpgui$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/dpgui.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/dpgui$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/dpgui$(DependSuffix): src/gui/dpgui.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/dpgui$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/dpgui$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/dpgui.cpp"

src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(ObjectSuffix): src/gui/DeltaPatcherDecodePanel.cpp src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherDecodePanel.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(DependSuffix): src/gui/DeltaPatcherDecodePanel.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherDecodePanel.cpp"

src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(ObjectSuffix): src/gui/DeltaPatcherMainDialog.cpp src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherMainDialog.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(DependSuffix): src/gui/DeltaPatcherMainDialog.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherMainDialog.cpp"

src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(ObjectSuffix): src/gui/DeltaPatcherEncodePanel.cpp src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherEncodePanel.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(DependSuffix): src/gui/DeltaPatcherEncodePanel.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherEncodePanel.cpp"

src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(ObjectSuffix): src/gui/DeltaPatcherDropTarget.cpp src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherDropTarget.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(DependSuffix): src/gui/DeltaPatcherDropTarget.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherDropTarget.cpp"

src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(ObjectSuffix): src/gui/DeltaPatcherAboutDialog.cpp src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherAboutDialog.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(DependSuffix): src/gui/DeltaPatcherAboutDialog.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/src/gui/DeltaPatcherAboutDialog.cpp"

$(IntermediateDirectory)/resource.rc$(ObjectSuffix): resource.rc
	@$(MakeDirCommand) "./Release"
	$(RcCompilerName) -i "D:/Documenti/CodeLite Projects/workspace/DeltaPatcher/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(RcIncludePath)

-include src/$(IntermediateDirectory)/*$(DependSuffix)
-include src/patcher/$(IntermediateDirectory)/*$(DependSuffix)
-include src/gui/$(IntermediateDirectory)/*$(DependSuffix)
-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) src/$(IntermediateDirectory)/DPApp$(ObjectSuffix)
	$(RM) src/$(IntermediateDirectory)/DPApp$(DependSuffix)
	$(RM) src/$(IntermediateDirectory)/DPApp$(PreprocessSuffix)
	$(RM) src/patcher/$(IntermediateDirectory)/XDeltaPatch$(ObjectSuffix)
	$(RM) src/patcher/$(IntermediateDirectory)/XDeltaPatch$(DependSuffix)
	$(RM) src/patcher/$(IntermediateDirectory)/XDeltaPatch$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/dpgui$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/dpgui$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/dpgui$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherDecodePanel$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherMainDialog$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherEncodePanel$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherDropTarget$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/DeltaPatcherAboutDialog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource.rc$(ObjectSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe


