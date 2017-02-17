//
//  TGMarker.mm
//  TangramMap
//
//  Created by Karim Naaji on 2/17/17.
//  Copyright (c) 2017 Mapzen. All rights reserved.
//

#import "TGMarker.h"
#import "TGMapViewController.h"
#import "TGMapViewController+Internal.h"
#import "tangram.h"

enum class TGMarkerType {
    point,
    polygon,
    polyline,
};

@interface TGMarker () {
    Tangram::Map* tangramInstance;
    Tangram::MarkerID identifier;
    TGMarkerType type;
}

@property (copy, nonatomic) NSString* styling;
@property (strong, nonatomic) TGGeoPolygon* polygon;
@property (strong, nonatomic) TGGeoPolyline* polyline;
@property (assign, nonatomic) TGGeoPoint point;

@end

@implementation TGMarker

- (BOOL)setMap:(TGMapViewController *)mapView
{
    // remove marker from current view
    if (!mapView && tangramInstance && identifier) {
        tangramInstance->markerRemove(identifier);
        tangramInstance = nil;
        return YES;
    }

    if (![mapView map] || [mapView map] == tangramInstance) { return NO; }

    // Removes the marker from the previous map view
    if (tangramInstance) {
        tangramInstance->markerRemove(identifier);
    }

    tangramInstance = [mapView map];

    // Create a new marker identifier for this view
    identifier = tangramInstance->markerAdd();

    if (!identifier) { return NO; }

    // Set the geometry type
    switch (type) {
        case TGMarkerType::point: {
            Tangram::LngLat lngLat(self.point.longitude, self.point.latitude);
            if (!tangramInstance->markerSetPoint(identifier, lngLat)) {
                return NO;
            }
        }
        break;
        case TGMarkerType::polygon:
            break;
        case TGMarkerType::polyline:
            break;
    }

    // Update styling
    if (self.styling) {
        if (!tangramInstance->markerSetStyling(identifier, [self.styling UTF8String])) {
            return NO;
        }
    }

    return YES;
}

@end

