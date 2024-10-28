%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec remove_subfolders(Folder :: [unicode:unicode_binary()]) -> [unicode:unicode_binary()].

split(S, Start, End) ->
    case End > byte_size(S) of
        true  -> <<"">>;
        false -> binary:part(S, Start, End)
    end.

char_at(S, Index) ->
    case Index >= byte_size(S) of
        true  -> 1;
        false -> binary:at(S, Index)
    end.

rx(Folders, Ans) ->
    lists:foldl(fun(Folder, Res) ->
                        [Last | _ ] = Res,
                        {LastLen, CurrLen} = {byte_size(Last), byte_size(Folder)},
                        Terms = (CurrLen =< LastLen) or (Last =/= split(Folder, 0, LastLen)),
                        Condition = (Terms) or (char_at(Folder, LastLen) =/= $/),
                        case Condition of
                            true  -> [Folder | Res];
                            false -> Res
                        end
                end, Ans, Folders).

remove_subfolders(Folders) ->
    [First | Rest] = lists:sort(Folders),
    lists:reverse(rx(Rest, [First])).
