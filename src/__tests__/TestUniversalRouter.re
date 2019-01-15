open UniversalRouter;
open Jest;
open ExpectJs;

let routes = {
  path: "/page", /* string or regexp or array of them, optional */
  name: "page",  /* unique string, optional */
  parent: None,  /* Some(route) object or None */
  children: Some([]), /* Some list of child route objects or None */
  /* what to do when route activated */
  action: (context, params) => {
    /* some action */
  }
};

let options = {
  context: { },
  baseUrl: "/base",
  resolveRoute: (context, params) => {
    if (typeof context.route.action === "function") {
      context.route.action(context, params);
    } else {
      unit
    };
  },
  errorHandler: (error, context) => {
    Js.log(error);
    Js.log(context);
    if error.status === 404 {
      "<h1>Page Not Found</h1>";
    } else {
      "<h1>Oops! Something went wrong</h1>";
    };
  }
};

describe("UniversalRouter", () => {
  test("#make w NO options", () =>
    expect(() =>
      make(routes)
    ) |> not |> toThrow
  );

  test("#make w options", () =>
    expect(() =>
      make(routes, ~options=options)
    ) |> not |> toThrow
  );

  describe("router instance", () => {
    let router = make(routes);
    let context = {
      title: "Home page"
    }
    let route = {
      pathname: "home",
      context: context
    }
    test("#resolve", () =>
      expect(() =>         
        router.resolve(route)
      ) |> not |> toThrow
    );
  });
});