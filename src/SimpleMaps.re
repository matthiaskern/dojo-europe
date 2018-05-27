let fromOption = Js.Nullable.fromOption;

module ComposableMap = {
  [@bs.module "react-simple-maps"]
  external composableMapClass : ReasonReact.reactClass = "ComposableMap";
  [@bs.deriving abstract]
  type projectionConfigT = {
    scale: int,
    rotation: array(int),
  };
  [@bs.deriving abstract]
  type jsProps = {
    width: Js.nullable(int),
    height: Js.nullable(int),
    projection: Js.nullable(string),
    projectionConfig: projectionConfigT,
  };
  let make =
      (~width=?, ~height=?, ~projection=?, ~projectionConfig, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=composableMapClass,
      ~props=
        jsProps(
          ~width=fromOption(width),
          ~height=fromOption(height),
          ~projection=fromOption(projection),
          ~projectionConfig=projectionConfig,
        ),
      children,
    );
};

module ZoomableGroup = {
  [@bs.module "react-simple-maps"]
  external zoomableGroupClass : ReasonReact.reactClass = "ZoomableGroup";
  [@bs.deriving abstract]
  type jsProps = {
    zoom: Js.nullable(int),
    center: Js.nullable(array(int)),
    disablePanning: Js.nullable(bool),
    /* style: Js.nullable(), */
    /* onMoveStart: Js.nullable(() => unit), */
  };
  let make = (~zoom=?, ~center=?, ~disablePanning=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=zoomableGroupClass,
      ~props=
        jsProps(
          ~zoom=fromOption(zoom),
          ~center=fromOption(center),
          ~disablePanning=fromOption(disablePanning),
        ),
      children,
    );
};

module Geography = {
  type projectionT;
  [@bs.deriving abstract]
  type geographyT = {id: string};
  [@bs.module "react-simple-maps"]
  external geographyClass : ReasonReact.reactClass = "Geography";
  [@bs.deriving abstract]
  type styleT = {
    default: ReactDOMRe.Style.t,
    hover: ReactDOMRe.Style.t,
    pressed: ReactDOMRe.Style.t,
  };
  [@bs.deriving abstract]
  type jsProps = {
    cacheId: Js.nullable(int),
    precision: Js.nullable(int),
    round: Js.nullable(bool),
    geography: Js.nullable(geographyT),
    tabable: Js.nullable(bool),
    projection: projectionT,
    style: Js.nullable(styleT),
  };
  let make =
      (
        ~cacheId=?,
        ~precision=?,
        ~round=?,
        ~geography=?,
        ~projection,
        ~tabable=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographyClass,
      ~props=
        jsProps(
          ~cacheId=fromOption(cacheId),
          ~precision=fromOption(precision),
          ~round=fromOption(round),
          ~geography=fromOption(geography),
          ~projection,
          ~tabable=fromOption(tabable),
          ~style=fromOption(style),
        ),
      children,
    );
};

module Geographies = {
  [@bs.module "react-simple-maps"]
  external geographiesClass : ReasonReact.reactClass = "Geographies";
  [@bs.deriving abstract]
  type jsProps = {
    disableOptimization: Js.nullable(bool),
    geography: Js.nullable(string) /* or object, or array */
  };
  let make = (~disableOptimization=?, ~geography=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=geographiesClass,
      ~props=
        jsProps(
          ~disableOptimization=fromOption(disableOptimization),
          ~geography=fromOption(geography),
        ),
      children,
    );
};

module Markers = {
  [@bs.module "react-simple-maps"]
  external markersClass : ReasonReact.reactClass = "Markers";

  let make = (children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markersClass,
      ~props=Js.Obj.empty(),
      children,
    );
};

module Marker = {
  [@bs.module "react-simple-maps"]
  external markerClass : ReasonReact.reactClass = "Marker";
  [@bs.deriving abstract]
  type markerT = {
    coordinates: array(float),
  };
  [@bs.deriving abstract]
  type jsProps = {
    marker: markerT,
  };
  let make = (~marker, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=markerClass,
      ~props=
        jsProps(
          ~marker=marker,
        ),
      children,
    );
};
