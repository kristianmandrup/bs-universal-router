module Router = {
  type t('c) = {
    resolve: (~pathname: string, ~context: 'c, unit) => Js.Promise.t('c),
  };
};
type _routes;
type _opts;
[@bs.new] [@bs.module "universal-router"]
external createRouter: (_routes, ~options: _opts, unit) => Router.t('c) =
  "Router";
let make = (routes, ~options, ()) => createRouter(routes, ~options, ());