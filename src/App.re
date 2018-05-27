type state = array(Fetcher.data);

type action =
  | Load
  | Update(array(Fetcher.data));

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  didMount: self =>
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations",
      ~cb=(locations =>self.send(Update(locations)))
    ),
  initialState: () => [||],
  reducer: (action, _state) =>
    switch (action) {
    | Load => ReasonReact.NoUpdate
    | Update(locations) => ReasonReact.Update(locations)
    },
  render: self => <MapDisplay locations=self.state />,
};
