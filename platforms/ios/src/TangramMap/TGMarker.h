//
//  TGMarker.h
//  TangramMap
//
//  Created by Karim Naaji on 2/17/17.
//  Copyright (c) 2017 Mapzen. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TGGeoPoint.h"
#import "TGGeoPolygon.h"
#import "TGGeoPolyline.h"

@class TGMapViewController;

NS_ASSUME_NONNULL_BEGIN

@interface TGMarker : NSObject

#if 0

/**
 Removes all the markers added to the map view.
 */
- (void)markerRemoveAll;

/**
 Creates a marker identifier which can be used to dynamically add points and polylines
 to the map.

 Example on how to add a point to the map for a geographic coordinate.

 ```swift
 var identifier = view.markerAdd()
 view.markerSetStyling(identifier, styling: "{ style: 'points', color: 'white', size: [25px, 25px], order:500 }")
 view.markerSetPoint(identifier, coordinates: TGGeoPointMake(longitude, latitude))
 ```

 @return a marker identifier, 0 if adding a marker failed
 @note The marker should be appropriately styled using `-markerSetStyling:styling:`
 and a type must be set (point, polyline, polygon) through `markerSetPoint*`, `markerSetPolyline` or `markerSetPolygon`
 for it to be visible.

 @note May return 0 if adding a marker failed, a marker identifier of 0 is non-valid.
 */
- (TGMapMarkerId)markerAdd;

/**
 Sets the styling for a marker identifier.

 See the more detailed scene <a href="https://mapzen.com/documentation/tangram/Styles-Overview/">documentation</a>
 to get more styling informations.

 @param identifier the marker identifier created with `-markerAdd`
 @param styling the styling string in YAML syntax to set to the marker

 @return `YES` if this operation was successful, `NO` otherwise

 @note It is possible to update the marker styling multiple times.
 */
- (BOOL)markerSetStyling:(TGMapMarkerId)identifier styling:(NSString *)styling;

/**
 Sets a marker to be a single point geometry at a geographic coordinate.

 @param identifier the marker identifier created with `-markerAdd`
 @param the longitude and latitude where the marker will be placed
 @return `YES` if this operation was successful, `NO` otherwise

 @note Markers can have their geometry set multiple time with possibly different geometry types.
 */
- (BOOL)markerSetPoint:(TGMapMarkerId)identifier coordinates:(TGGeoPoint)coordinate;

/**
 Similar to `-[TGMapViewController markerSetPoint:coordinates:]` except that the point will transition to the
 geographic coordinate with a transition of time `seconds` and with an ease type function of type `ease`
 (See `TGEaseType`) from its previous coordinate, if a point geometry hasn't been set any coordinate yet,
 this method will act as `-markerSetPoint:coordinates:`.

 @param identifier the marker identifier created with `-markerAdd`
 @param the longitude and latitude where the marker will be placed
 @param seconds the animation duration given in seconds
 @param ease the ease function to be used between animation timestep
 @return `YES` if this operation was successful, `NO` otherwise

 @note Markers can have their geometry set multiple time with possibly different geometry types.
 */
- (BOOL)markerSetPointEased:(TGMapMarkerId)identifier coordinates:(TGGeoPoint)coordinate seconds:(float)seconds easeType:(TGEaseType)ease;

/**
 Sets a marker styled to be a polyline (described in a `TGGeoPolyline`).

 @param identifier the marker identifier created with `-markerAdd`
 @oaram polyline the polyline geometry to use for this marker
 @return `YES` if this operation was successful, `NO` otherwise

 @note Markers can have their geometry set multiple time wwith possibly different geometry types.
 */
- (BOOL)markerSetPolyline:(TGMapMarkerId)identifier polyline:(TGGeoPolyline *)polyline;

/**
 Sets a marker to be a polygon geometry (described in a `TGGeoPolygon`).

 @param identifier the marker identifier created with `-[TGMapViewController markerAdd]`
 @param polygon the polygon geometry to use for this marker
 @return `YES` if this operation was successful, `NO` otherwise

 @note Markers can have their geometry set multiple time with possibly different geometry types.
 */
- (BOOL)markerSetPolygon:(TGMapMarkerId)identifier polygon:(TGGeoPolygon *)polygon;

/**
 Adjusts marker visibility

 @param identifier the marker identifier created with `- markerAdd`
 @param whether the marker is set to visible
 @return `YES` if this operation was successful, `NO` otherwise
 */
- (BOOL)markerSetVisible:(TGMapMarkerId)identifier visible:(BOOL)visible;

/**
 Sets an image loaded with a <a href="https://developer.apple.com/reference/uikit/uiimage">
 UIImage</a> to a marker styled with a <a href="https://mapzen.com/documentation/tangram/Styles-Overview/#points">
 points style</a>.

 ```swift
 var identifier = view.markerAdd()
 view.markerSetStyling(identifier, styling: "{ style: 'points', color: 'white', size: [25px, 25px], order:500 }")
 view.markerSetPoint(identifier, coordinates: TGGeoPointMake(longitude, latitude))
 view.markerSetImage(identifier, image: UIIMage(name: "marker-image.png"))
 ```

 @param identifier the marker identifier created with `-markerAdd`
 @param the `UIImage` that will be used to be displayed on the marker
 @return `YES` if this operation was successful, `NO` otherwise

 @note An image marker must be styled with a
 <a href="https://mapzen.com/documentation/tangram/Styles-Overview/#points">point style</a>.
 */
- (BOOL)markerSetImage:(TGMapMarkerId)identifier image:(UIImage *)image;

/**
 Removes a marker for a marker identifier.

 @param identifier the marker identifier created with `-markerAdd`
 @return `YES` if removal was succesful, `NO` otherwise
 */
- (BOOL)markerRemove:(TGMapMarkerId)identifier;

#endif

@property (weak, nonatomic) TGMapViewController* map;

NS_ASSUME_NONNULL_END

@end
