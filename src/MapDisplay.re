let component = ReasonReact.statelessComponent("App");

open SimpleMaps;

let createMarker = (_name, (lng, lat)) => {
  <Marker marker=(Marker.markerT(~coordinates=[|lat, lng|]))><circle cx="0" cy="0" r="8" fill="rgba(255, 0, 0, 0.7)" /></Marker>;
}

let createMarkers = locations =>
  Array.map(
    data => {
      createMarker(Fetcher.username(data), Fetcher.location(data));
    },
    locations,
  );

let make = (~locations: array(Fetcher.data), _children) => {
  ...component,
  render: _self =>
    <ComposableMap
      projectionConfig=(
        ComposableMap.projectionConfigT(
          ~scale=205,
          ~rotation=[|(-11), 0, 0|],
        )
      )>
      <ZoomableGroup>
        <Geographies geography="world-50m.json">
          (
            (geographies, projection) =>
              Array.map(
                geography =>
                  <Geography
                    key=(Geography.id(geography))
                    geography
                    projection
                    style=(
                      Geography.styleT(
                        ~default=
                          ReactDOMRe.Style.make(
                            ~fill="black",
                            ~stroke="gray",
                            ~strokeWidth="0.75px",
                            ~outline="none",
                            (),
                          ),
                        ~hover=
                          ReactDOMRe.Style.make(
                            ~fill="black",
                            ~stroke="gray",
                            ~strokeWidth="0.75px",
                            ~outline="none",
                            (),
                          ),
                        ~pressed=
                          ReactDOMRe.Style.make(
                            ~fill="black",
                            ~stroke="gray",
                            ~strokeWidth="0.75px",
                            ~outline="none",
                            (),
                          ),
                      )
                    )
                  />,
                geographies,
              )
          )
        </Geographies>
        <Markers> (createMarkers(locations)) </Markers>
      </ZoomableGroup>
    </ComposableMap>,
};
