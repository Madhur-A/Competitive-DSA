



class Solution {
public:
    string pushDominoes(string dominoes) {
		int const n = dominoes.length();
		std::vector<int> forces(n);
		for(int i = 0, f = 0; i < n; ++i) {
			f = (dominoes[i] == 'R') ? n : f;
			f = (dominoes[i] == 'L') ? 0 : f;
			f = (dominoes[i] == '.') ? std::max(f-1, 0) : f;
			forces[i] += f;
		}

		for(int i = n - 1, f = 0; 0 <= i; --i) {
			f = (dominoes[i] == 'L') ? n : f;
			f = (dominoes[i] == 'R') ? 0 : f;
			f = (dominoes[i] == '.') ? std::max(f-1, 0) : f;

			forces[i] -= f;
			dominoes[i] = (forces[i]  < 0) ? 'L' : (forces[i]  > 0) ? 'R' : '.';
		}

		return dominoes;
    }
};

