open UniversalRouter;
open Jest;
open ExpectJs;

type params;
type context = {route};
type route = {
  path: string,
  name: string,
  parent: option(unit),
  children: option(array(route)),
  action: (context, params) => unit,
};

let myRoutes = {
  path: "/page", /* string or regexp or array of them, optional */
  name: "page", /* unique string, optional */
  parent: None, /* Some(route) object or None */
  children: Some([||]), /* Some list of child route objects or None */
  /* what to do when route activated */
  action: (context, params) => {
    ();
  },
};

type result;
type error;

type options = {
  context,
  baseUrl: string,
  resolveRoute: (context, params) => result,
  errorHandler: (error, context) => string,
};

let myOptions: options = {
  context: {
    title: "x",
  },
  baseUrl: "/base",
  resolveRoute: (context, params) =>
    if (context.route.action) {
      context.route.action(context, params);
    } else {
      unit;
    },
  errorHandler: (error, context) =>
    /* Js.log(error);
       Js.log(context); */
    if (error.status === 404) {
      "<h1>Page Not Found</h1>";
    } else {
      "<h1>Oops! Something went wrong</h1>";
    },
};

describe("UniversalRouter", () => {
  test("#make w NO options", () =>
    expect(() =>
      make(myRoutes)
    ) |> not |> toThrow
  );

  test("#make w options", () =>
    expect(() =>
      make(myRoutes, ~options)
    ) |> not |> toThrow
  );

  describe("router instance", () => {
    let router = make(myRoutes);
    let context = {title: "Home page"};
    let route = {pathname: "home", context};
    test("#resolve", () =>
      expect(() =>
        router.resolve(route)
      ) |> not |> toThrow
    );
  });
});