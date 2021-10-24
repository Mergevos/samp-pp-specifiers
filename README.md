# samp-pp-specifiers

[![sampctl](https://img.shields.io/badge/sampctl-samp--pp--specifiers-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-pp-specifiers)

Make your specifiers with PawnPlus plugin.

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-pp-specifiers
```

Include in your code and begin using the library:

```pawn
#include <pp-specifiers>
```

## Usage

Register your own specifiers with this function:

```pawn
stock PP_RegisterSpecifier(specifier, const handler[], bool:is_string=false)

//Example

PP_RegisterSpecifier('g', "SomeCallbackToHandle", false);

print_s(str_format("He is %g connected.", playerid));

forward String: SomeCallbackToHandle(playerid, type, String: format);
public String: SomeCallbackToHandle(playerid, type, String: format)
{
  if(!IsPlayerConnected(playerid))
  {
    return str_new("Not connected");
  }
  return str_new("Connected");
}
```

Firstly, we register specifier character with handler function, and our specifier doesn't accept normal strings, so you can't specify NORMAL (not PawnPlus) string instead of playerid. `print_s` part is pretty straightforward.

`public String: SomeCallbackToHandle(playerid, type, String: format)` is handler. It is basically a function which handles the specifier. `type` is character of the specifier, in this case it is `g`. `String: format` is pawnplus string of everything you input in front of specifier, eg. `%03g`, will make format `03`. 

|--|
New Specifiers|
%a|
%m|
|--|

## Testing

To test, simply run the package:

```bash
sampctl package run
```
