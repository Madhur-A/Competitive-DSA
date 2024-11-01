-module(kata).
-export([next_higher/1]).
% "Ooarai Joshigakuin Shōri!"

next_higher(X) ->
  S = X band -X,
  R = X + S,
  O = X bxor R,
  P = (O bsr 2) div S,
  R bor P.
