-module(kata).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi").
%% -export([stockList/2]).

-spec stockList([string], [string]) -> [{string, integer}].

as_int(S) ->
    case string:to_integer(S) of
        {error, _} -> 0;
        {Int,   _} -> Int
    end.

update(Key, Value, G) ->
    case dict:find(Key, G) of
        error         -> dict:store(Key, Value, G);
        {ok, Fetched} -> dict:store(Key, Value + Fetched, G)
    end.

load(            [], G) -> G;
load([Book | Books], G) ->
    [Key, Value] = string:tokens(Book, " "),
    load(Books, update(string:sub_string(Key, 1, 1), as_int(Value), G)).

get_mappings(        [], _, Res) -> Res;
get_mappings([Key | R ], G, Res) ->
    case dict:find(Key, G) of
        error -> get_mappings(R, G, [{Key, 0}] ++ Res);
        _     -> get_mappings(R, G, [{Key, dict:fetch(Key, G)}] ++ Res)
    end.

stockList(         [], ListOfCategories) -> [];
stockList(ListOfBooks, ListOfCategories) ->
  lists:reverse(get_mappings(ListOfCategories, load(ListOfBooks, dict:new()), [])).

clear() ->
    io:format("\ec").
