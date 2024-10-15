%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec get_maximum_xor(Nums :: [integer()], MaximumBit :: integer()) -> [integer()].

get_maximum_xor(Nums, MaximumBit) ->
    Mask = (1 bsl MaximumBit) - 1,
    lists:reverse(element(1, lists:mapfoldl(fun(Num, Res) -> {Num bxor Res bxor Mask, Num bxor Res} end, 0, Nums))).
