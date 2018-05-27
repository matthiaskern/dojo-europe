let component = ReasonReact.statelessComponent("App");

open SimpleMaps;

let make = _children => {
  ...component,
  render: _self =>
    <ComposableMap projectionConfig=ComposableMap.projectionConfigT(~scale=205, ~rotation=[|(-11), 0, 0|])>
      <ZoomableGroup>
        <Geographies geography="world-50m.json">
        (
          (geographies, projection) =>
            Array.map((geography) =>
              <Geography key=Geography.id(geography) geography projection style=Geography.styleT(
                ~default=ReactDOMRe.Style.make(~fill="black", ~stroke="gray", ~strokeWidth="0.75px", ~outline="none", ()),
                ~hover=ReactDOMRe.Style.make(~fill="black", ~stroke="gray", ~strokeWidth="0.75px", ~outline="none", ()),
                ~pressed=ReactDOMRe.Style.make(~fill="black", ~stroke="gray", ~strokeWidth="0.75px", ~outline="none", ())
              ) />
              ,geographies)
        )
        </Geographies>
      </ZoomableGroup>
    </ComposableMap>,
};
