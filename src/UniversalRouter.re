module Router = {
  type t('c) = {
    resolve: (~pathname: string, ~context: 'c, unit) => Js.Promise.t('c),
  };
};

[@bs.module "universal-router"]
external make: ('a, ~options: 'b, unit) => Router.t('c) = "new";