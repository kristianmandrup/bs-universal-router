# bs-universal-router

Bucklescript bindings for [Universal Router](https://www.kriasoft.com/universal-router/)

## Use

`bs-universal-router` can be used with modern state management solutions like [Meiosis](https://meiosis.js.org/) to great effect. No need for Virtual DOMs or other "complex machinery" at this point in time ;)

See this [video example](https://www.youtube.com/watch?v=0mhpECObLdc&index=4&list=UUl5aITiWNhBj8xx_rXjh6ZA)

## Writing bindings

To help write bucklescript bindings for this lib (and hence make it usable from ReasonML) see the [FFI cheatsheet](https://github.com/glennsl/bucklescript-ffi-cheatsheet) and go for it!

### Install

`npm i bs-universal-router`

Add `bs-universal-router` to `dependencies` in `bsconfig.json`

## Api

See [Universal router API](https://github.com/kriasoft/universal-router/blob/master/docs/api.md)

### Api changes

TODO

### Usage

```javascript
open UniversalRouter;

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

let router = UniversalRouter.make(routes, ~options=options);
```

## Build

```
npm run build
```

## Watch

```
npm run watch
```

## Editor

If you use `vscode`, Press `Windows + Shift + B` it will build automatically
