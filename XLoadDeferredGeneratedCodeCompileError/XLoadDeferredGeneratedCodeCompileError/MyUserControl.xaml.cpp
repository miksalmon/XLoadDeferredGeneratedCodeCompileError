#include "pch.h"
#include "MyUserControl.xaml.h"
#if __has_include("MyUserControl.g.cpp")
#include "MyUserControl.g.cpp"
#endif

#include <winrt/Windows.ApplicationModel.Resources.h>
#include <winrt/Microsoft.Windows.ApplicationModel.Resources.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace winrt::Microsoft::Windows::ApplicationModel::Resources;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::XLoadDeferredGeneratedCodeCompileError::implementation
{
	winrt::hstring MyUserControl::GetLocalizedText(winrt::hstring resourceId)
	{
		auto resourceLoader = ResourceLoader(ResourceLoader::GetDefaultResourceFilePath(), L"Resources");

		return resourceLoader.GetString(resourceId);
	}

	bool MyUserControl::IsTextBlockLoaded()
	{
		return m_isTextBlockLoaded;
	}

	void MyUserControl::IsTextBlockLoaded(bool v)
	{
		m_isTextBlockLoaded = v;
		RaisePropertyChanged(*this, to_hstring(__func__));
	}

	void winrt::XLoadDeferredGeneratedCodeCompileError::implementation::MyUserControl::MyButton_Click(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& /*e*/)
	{
		IsTextBlockLoaded(!IsTextBlockLoaded());
	}
}
