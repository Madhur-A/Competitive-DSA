-module(kata).
-export([oper/2, vertMirror/1, horMirror/1]).
% "Ooarai Joshigakuin Shōri!"

-spec vertMirror(string) -> string.
-spec horMirror(string) -> string.
-spec oper(fun((string) -> string), string) -> string.

vertMirror(Str) ->
  lists:concat(lists:join("\n" , [lists:reverse(Substr) || Substr <- string:tokens(Str, "\n")])).

horMirror(Str) ->
  lists:concat(lists:join("\n" , lists:reverse(string:tokens(Str, "\n")))).

oper(Func, S) ->
  Func(S).
