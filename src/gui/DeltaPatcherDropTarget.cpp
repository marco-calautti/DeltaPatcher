#include "DeltaPatcherDropTarget.h"

DeltaPatcherDropTarget::DeltaPatcherDropTarget(DeltaPatcherDropHandler* h)
{
	handler=h;
}

bool DeltaPatcherDropTarget::OnDropFiles(wxCoord x,wxCoord y,const wxArrayString& filenames)
{
	return handler->HandleFileDrop(filenames);
}