template <typename C>
std::vector<int> Z_Algorithm(const C& seq){
    auto s = seq.size();
    std::vector<int> res(s);
    res[0] = s;

    int i = 1, j = 0; // satisfying seq[0..j) = seq[i..i+j)
    while(i < s){
        while(i + j < s && seq[j] == seq[i+j]){
            j += 1;
        }
        res[i] = j;
        if(j == 0){
            i += 1;
            continue;
        }
        int k = 1;
        while(i + k < s && k + res[k] < j){
            res[i+k] = res[k];
            k += 1;
        }
        i += k;
        j -= k;
    }

    return res;
}