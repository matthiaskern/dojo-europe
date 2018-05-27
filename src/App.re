type state = {locations: array((float, float))};

type action =
  | Load;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {locations: [|(100.0, 100.0)|]},
  reducer: (action, _state) =>
    switch (action) {
    | Load => ReasonReact.NoUpdate
    },
  render: self => <MapDisplay locations=self.state.locations />,
};
