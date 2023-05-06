struct ConvexHullTrick{
    using Line = std::tuple<ll, ll>;
    std::vector<Line> lines;

    void addLine(ll a, ll b){
        while(lines.size() >= 2){
            ll a1, b1, a2, b2;
            std::tie(a1, b1) = *(lines.rbegin() + 1);
            std::tie(a2, b2) = *lines.rbegin();

            if(-(b - b1) * (a - a2) < -(b - b2) * (a - a1)){
                break;
            }else{
                lines.pop_back();
            }
        }

        lines.emplace_back(a, b);
    }

    ll maximum(ll x){
        int n = lines.size();
        int lb = 0, ub = n;

        auto at = [](ll x, Line l) -> ll {
            ll a, b;
            std::tie(a, b) = l;

            return a * x + b;
        };

        while(ub - lb > 2){
            int m1 = (2 * lb + 1 * ub) / 3, m2 = (1 * lb + 2 * ub) / 3;

            ll y1 = at(x, lines[m1]), y2 = at(x, lines[m2]);
            if(y1 < y2){
                lb = m1;
            }else{
                ub = m2;
            }
        }

        ll y = at(x, lines[lb]);

        if(ub - lb == 2){
            y = std::max(y, at(x, lines[lb + 1]));
        }

        return y;
    }
};