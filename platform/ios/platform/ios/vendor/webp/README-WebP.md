## Add `libwebp` for Decoding WebP raster tiles

> *WebP is an open source image format that provides smaller file sizes and lossy & lossless formats.*

1.  Add `libwebp` as a Swift Package

This was left out of the commit as the Xcode Project files are XML based and can be cumbersome to merge.  It's easier to manually go through these

To add a package dependency to your Xcode project, select File > Swift Packages > Add Package Dependency and enter its repository URL. See [Adding Package Dependencies to Your App.](https://developer.apple.com/documentation/xcode/adding_package_dependencies_to_your_app)

2. repository URL - `https://github.com/SDWebImage/libwebp-Xcode`

3.  Be sure to *Add to Target* with the setting of the `dynamic` scheme

<img src="https://user-images.githubusercontent.com/118112/112783147-82482580-9003-11eb-8bae-387c8b5b099a.png" width=50%>


4. checkout the branch `webp-ios`

```bash
cd platform/ios
```

5.  Setup & open the Xcode Workspace

```bash
make iproj
```

6.  `libwebp` has been added to the `dynamic`, scheme and is now part of the `xcframework` when you build.  You should now be able to use WebP rasters in your styles.

Here is a basic style for adding a WebP raster layer for Joshua Tree National Park.

```json
{
  "version": 8,
  "name": "Joshua Tree National Park...in WebP",
  "center": [-115.746, 33.866],
  "zoom": 7,
  "sources": {
    "jotr": {
        "tiles": [ "asset://joshuatree/{z}/{x}/{y}.webp" ],
        "type": "raster"
    }
  },
  "layers": [
    {
      "id": "background",
      "type": "background",
      "paint": {
        "background-color": "#ddeeff"
      }
    },
    {
        "id": "jotr",
        "type": "raster",
        "source": "jotr",
        "layout": {},
        "paint": {}
    }
  ]
}
```

This work is donated by [ePi Rational, Inc.](https://roblabs.com/webp/) based on work initially done by [mapbox/mapbox-gl-native](https://github.com/mapbox/mapbox-gl-native)

And updated over several versions of the iOS SDK.

* [WebP for Mapbox SDK for iOS v3.6.0](https://github.com/roblabs/mapbox-gl-native/blob/546374c0149d5ce6bdaa2aba595cc5e81b1dbcbf/README.md) in July 2017
* [WebP for Mapbox SDK for iOS v5.1.1](https://github.com/roblabs/mapbox-gl-native/commits/Features/ios-v5.1.1-webp) in July 2019

---

<img src="https://user-images.githubusercontent.com/118112/112783126-7492a000-9003-11eb-9bc4-8a5486b949c1.png" width=50%>
