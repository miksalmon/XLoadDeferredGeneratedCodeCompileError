#pragma once

#include "MyUserControl.g.h"

#include "PropertyChangedEventBase.h"
#include <winrt/Windows.Foundation.h>

namespace winrt::XLoadDeferredGeneratedCodeCompileError::implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl>, ::XLoadDeferredGeneratedCodeCompileError::PropertyChangedEventBase
    {
        MyUserControl()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        winrt::hstring GetLocalizedText(winrt::hstring resourceId);

        bool IsTextBlockLoaded();
        void IsTextBlockLoaded(bool v);

        void MyButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        bool m_isTextBlockLoaded{ false };
    };
}

namespace winrt::XLoadDeferredGeneratedCodeCompileError::factory_implementation
{
    struct MyUserControl : MyUserControlT<MyUserControl, implementation::MyUserControl>
    {
    };
}
