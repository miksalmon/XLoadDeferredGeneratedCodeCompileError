// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <winrt/Microsoft.UI.Xaml.Data.h>

using namespace winrt::Microsoft::UI::Xaml::Data;

namespace XLoadDeferredGeneratedCodeCompileError
{
    struct PropertyChangedEventBase
    {
    protected:
        PropertyChangedEventBase() = default;
        virtual ~PropertyChangedEventBase() = default;

    public:
        // To avoid C26432 warnings, insist on "rule of five".
        // https://docs.microsoft.com/en-us/cpp/code-quality/c26432?view=msvc-160
        PropertyChangedEventBase(const PropertyChangedEventBase&) = delete;
        PropertyChangedEventBase(PropertyChangedEventBase&&) = delete;
        PropertyChangedEventBase& operator=(const PropertyChangedEventBase&) = delete;
        PropertyChangedEventBase& operator=(PropertyChangedEventBase&&) = delete;

        winrt::event_token PropertyChanged(PropertyChangedEventHandler const& value)
        {
            return m_propertyChanged.add(value);
        }

        void PropertyChanged(winrt::event_token const& token)
        {
            m_propertyChanged.remove(token);
        }

        template<class PropertyType>
        bool SetProperty(winrt::Windows::Foundation::IInspectable const& sender, char const* propertyName, PropertyType& store, PropertyType newValue)
        {
            return SetProperty(sender, winrt::to_hstring(propertyName), store, newValue);
        }

        template<class PropertyType>
        bool SetProperty(winrt::Windows::Foundation::IInspectable const& sender, winrt::hstring const& propertyName, PropertyType& store, PropertyType newValue)
        {
            if (store != newValue)
            {
                store = newValue;
                RaisePropertyChanged(sender, propertyName);
                return true;
            }

            return false;
        }

        void RaisePropertyChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::hstring const& propertyName)
        {
            if (m_propertyChanged)
            {
                m_propertyChanged(sender, PropertyChangedEventArgs(propertyName));
            }
        }

    private:
        winrt::event<PropertyChangedEventHandler> m_propertyChanged;
    };
}
