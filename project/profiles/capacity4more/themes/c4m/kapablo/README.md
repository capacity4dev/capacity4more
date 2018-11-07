# Kapablo theme

The kapablo (Esperanto for capacity) theme is the default theme for the
capacity4more project.

## Installation

The theme is created using sass, svg icons, …

The css is not included in this folder. You need to build it from within the
build folders:

```
$ cd <root of the theme>/build
$ npm install
$ gulp build
```

## Development

Changing the styling is done by changing the sass/* files within the theme
folder.

You can watch for changes and auto rebuild the files:

```
$ cd <root of the theme>/build
$ gulp watch
```
