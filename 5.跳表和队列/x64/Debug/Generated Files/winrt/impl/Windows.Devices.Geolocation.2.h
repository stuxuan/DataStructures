// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210806.1

#pragma once
#ifndef WINRT_Windows_Devices_Geolocation_2_H
#define WINRT_Windows_Devices_Geolocation_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Devices.Geolocation.1.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Geolocation
{
    struct BasicGeoposition
    {
        double Latitude;
        double Longitude;
        double Altitude;
    };
    inline bool operator==(BasicGeoposition const& left, BasicGeoposition const& right) noexcept
    {
        return left.Latitude == right.Latitude && left.Longitude == right.Longitude && left.Altitude == right.Altitude;
    }
    inline bool operator!=(BasicGeoposition const& left, BasicGeoposition const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) CivicAddress : winrt::Windows::Devices::Geolocation::ICivicAddress
    {
        CivicAddress(std::nullptr_t) noexcept {}
        CivicAddress(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::ICivicAddress(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeoboundingBox : winrt::Windows::Devices::Geolocation::IGeoboundingBox
    {
        GeoboundingBox(std::nullptr_t) noexcept {}
        GeoboundingBox(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeoboundingBox(ptr, take_ownership_from_abi) {}
        GeoboundingBox(winrt::Windows::Devices::Geolocation::BasicGeoposition const& northwestCorner, winrt::Windows::Devices::Geolocation::BasicGeoposition const& southeastCorner);
        GeoboundingBox(winrt::Windows::Devices::Geolocation::BasicGeoposition const& northwestCorner, winrt::Windows::Devices::Geolocation::BasicGeoposition const& southeastCorner, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        GeoboundingBox(winrt::Windows::Devices::Geolocation::BasicGeoposition const& northwestCorner, winrt::Windows::Devices::Geolocation::BasicGeoposition const& southeastCorner, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
        static auto TryCompute(param::iterable<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& positions);
        static auto TryCompute(param::iterable<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem);
        static auto TryCompute(param::iterable<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geocircle : winrt::Windows::Devices::Geolocation::IGeocircle
    {
        Geocircle(std::nullptr_t) noexcept {}
        Geocircle(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeocircle(ptr, take_ownership_from_abi) {}
        Geocircle(winrt::Windows::Devices::Geolocation::BasicGeoposition const& position, double radius);
        Geocircle(winrt::Windows::Devices::Geolocation::BasicGeoposition const& position, double radius, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        Geocircle(winrt::Windows::Devices::Geolocation::BasicGeoposition const& position, double radius, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geocoordinate : winrt::Windows::Devices::Geolocation::IGeocoordinate,
        impl::require<Geocoordinate, winrt::Windows::Devices::Geolocation::IGeocoordinateWithPositionData, winrt::Windows::Devices::Geolocation::IGeocoordinateWithPoint, winrt::Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp>
    {
        Geocoordinate(std::nullptr_t) noexcept {}
        Geocoordinate(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeocoordinate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeocoordinateSatelliteData : winrt::Windows::Devices::Geolocation::IGeocoordinateSatelliteData,
        impl::require<GeocoordinateSatelliteData, winrt::Windows::Devices::Geolocation::IGeocoordinateSatelliteData2>
    {
        GeocoordinateSatelliteData(std::nullptr_t) noexcept {}
        GeocoordinateSatelliteData(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeocoordinateSatelliteData(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Geolocator : winrt::Windows::Devices::Geolocation::IGeolocator,
        impl::require<Geolocator, winrt::Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy, winrt::Windows::Devices::Geolocation::IGeolocator2>
    {
        Geolocator(std::nullptr_t) noexcept {}
        Geolocator(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeolocator(ptr, take_ownership_from_abi) {}
        Geolocator();
        static auto RequestAccessAsync();
        static auto GetGeopositionHistoryAsync(winrt::Windows::Foundation::DateTime const& startTime);
        static auto GetGeopositionHistoryAsync(winrt::Windows::Foundation::DateTime const& startTime, winrt::Windows::Foundation::TimeSpan const& duration);
        [[nodiscard]] static auto IsDefaultGeopositionRecommended();
        static auto DefaultGeoposition(winrt::Windows::Foundation::IReference<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& value);
        [[nodiscard]] static auto DefaultGeoposition();
    };
    struct __declspec(empty_bases) Geopath : winrt::Windows::Devices::Geolocation::IGeopath
    {
        Geopath(std::nullptr_t) noexcept {}
        Geopath(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeopath(ptr, take_ownership_from_abi) {}
        explicit Geopath(param::iterable<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& positions);
        Geopath(param::iterable<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        Geopath(param::iterable<winrt::Windows::Devices::Geolocation::BasicGeoposition> const& positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geopoint : winrt::Windows::Devices::Geolocation::IGeopoint
    {
        Geopoint(std::nullptr_t) noexcept {}
        Geopoint(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeopoint(ptr, take_ownership_from_abi) {}
        explicit Geopoint(winrt::Windows::Devices::Geolocation::BasicGeoposition const& position);
        Geopoint(winrt::Windows::Devices::Geolocation::BasicGeoposition const& position, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        Geopoint(winrt::Windows::Devices::Geolocation::BasicGeoposition const& position, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geoposition : winrt::Windows::Devices::Geolocation::IGeoposition,
        impl::require<Geoposition, winrt::Windows::Devices::Geolocation::IGeoposition2>
    {
        Geoposition(std::nullptr_t) noexcept {}
        Geoposition(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeoposition(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Geovisit : winrt::Windows::Devices::Geolocation::IGeovisit
    {
        Geovisit(std::nullptr_t) noexcept {}
        Geovisit(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeovisit(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeovisitMonitor : winrt::Windows::Devices::Geolocation::IGeovisitMonitor
    {
        GeovisitMonitor(std::nullptr_t) noexcept {}
        GeovisitMonitor(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeovisitMonitor(ptr, take_ownership_from_abi) {}
        GeovisitMonitor();
        static auto GetLastReportAsync();
    };
    struct __declspec(empty_bases) GeovisitStateChangedEventArgs : winrt::Windows::Devices::Geolocation::IGeovisitStateChangedEventArgs
    {
        GeovisitStateChangedEventArgs(std::nullptr_t) noexcept {}
        GeovisitStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeovisitStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeovisitTriggerDetails : winrt::Windows::Devices::Geolocation::IGeovisitTriggerDetails
    {
        GeovisitTriggerDetails(std::nullptr_t) noexcept {}
        GeovisitTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IGeovisitTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PositionChangedEventArgs : winrt::Windows::Devices::Geolocation::IPositionChangedEventArgs
    {
        PositionChangedEventArgs(std::nullptr_t) noexcept {}
        PositionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IPositionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StatusChangedEventArgs : winrt::Windows::Devices::Geolocation::IStatusChangedEventArgs
    {
        StatusChangedEventArgs(std::nullptr_t) noexcept {}
        StatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VenueData : winrt::Windows::Devices::Geolocation::IVenueData
    {
        VenueData(std::nullptr_t) noexcept {}
        VenueData(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Geolocation::IVenueData(ptr, take_ownership_from_abi) {}
    };
}
#endif
