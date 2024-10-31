-module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"
%% -export([stockList/2]).

-spec stockList([string], [string]) -> [{string, integer}].

single_shot([], C) -> [];
single_shot( B, C) ->
    lists:map(fun(E) ->
                      {E, lists:foldl(fun(F, Acc) ->
                                          case string:sub_string(F, 1, 1) =:= E of
                                              true  -> Acc + element(1, string:to_integer(lists:last(string:tokens(F, " "))));
                                              false -> Acc
                                          end
                                  end,
                                  0,
                                  B)}
              end, C).

stockList(ListOfBooks, ListOfCategories) -> single_shot(ListOfBooks, ListOfCategories).
