module Router = {
  type t('c) = {
    resolve: (~pathname: string, ~context: 'c, unit) => Js.Promise
  };
};

[@bs.module "universal-router"] 
external make: (routes: 'a, ~options: 'b, unit) => Router.t('c) = "new";
