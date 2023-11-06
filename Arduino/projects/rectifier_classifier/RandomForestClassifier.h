#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(const int8_t *x) {
                        uint8_t votes[5] = { 0 };
                        // tree #1
                        if (x[995] <= 59.5) {
                            if (x[312] <= 42.5) {
                                if (x[1231] <= 10.5) {
                                    if (x[400] <= 26.5) {
                                        if (x[1887] <= 25.0) {
                                            if (x[1839] <= -50.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[954] <= 36.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[755] <= 9.5) {
                                            if (x[869] <= 15.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[713] <= 14.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1080] <= 67.5) {
                                        if (x[1116] <= 14.5) {
                                            if (x[1550] <= 14.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1162] <= 24.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1161] <= 39.0) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[455] <= 39.5) {
                                    if (x[824] <= 37.5) {
                                        if (x[29] <= 37.5) {
                                            if (x[1241] <= 75.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[364] <= 11.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[166] <= 38.0) {
                                            if (x[1630] <= 51.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1949] <= 47.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1892] <= 43.5) {
                                        if (x[240] <= 73.5) {
                                            if (x[311] <= 51.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1395] <= 43.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1483] <= 80.5) {
                                            if (x[21] <= 31.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1305] <= 52.0) {
                                if (x[1671] <= 25.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[581] <= 52.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #2
                        if (x[1674] <= 56.5) {
                            if (x[432] <= 42.5) {
                                if (x[1630] <= 15.5) {
                                    if (x[160] <= 21.5) {
                                        if (x[295] <= 18.0) {
                                            if (x[967] <= 17.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[467] <= 8.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[595] <= 10.0) {
                                            if (x[80] <= 37.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[240] <= 48.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[433] <= 9.5) {
                                        if (x[470] <= 12.5) {
                                            if (x[1722] <= 42.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1443] <= 0.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[41] <= 62.5) {
                                            if (x[960] <= 21.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1279] <= 43.5) {
                                    if (x[1246] <= 22.5) {
                                        if (x[1540] <= 24.5) {
                                            if (x[379] <= 26.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1077] <= 49.5) {
                                            if (x[1014] <= 48.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[165] <= 58.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1261] <= 48.5) {
                                        if (x[350] <= 54.0) {
                                            if (x[761] <= 48.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[885] <= 32.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1869] <= 48.5) {
                                            if (x[215] <= 42.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[909] <= 52.5) {
                                if (x[1806] <= 20.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[1223] <= 46.5) {
                                    if (x[449] <= 53.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[4] += 1;
                                    }
                                }

                                else {
                                    if (x[388] <= 51.5) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #3
                        if (x[1634] <= 56.5) {
                            if (x[991] <= 43.5) {
                                if (x[1440] <= 20.5) {
                                    if (x[1006] <= 4.5) {
                                        if (x[1847] <= 16.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[666] <= 2.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1311] <= 11.0) {
                                            if (x[1828] <= -2.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[415] <= 22.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1189] <= 8.5) {
                                        if (x[875] <= 10.0) {
                                            if (x[760] <= 26.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[575] <= 17.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1481] <= 57.5) {
                                            if (x[1115] <= 16.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[712] <= 36.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[879] <= 41.5) {
                                    if (x[1392] <= 41.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1421] <= 41.0) {
                                            if (x[1743] <= 48.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1772] <= 48.5) {
                                        if (x[1200] <= 23.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[629] <= 53.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[266] <= 47.0) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[910] <= 56.5) {
                                if (x[395] <= 59.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[388] <= 49.5) {
                                    if (x[1350] <= 59.5) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[308] <= 52.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #4
                        if (x[75] <= 60.5) {
                            if (x[831] <= 40.5) {
                                if (x[550] <= 17.5) {
                                    if (x[1075] <= 8.5) {
                                        if (x[286] <= -2.5) {
                                            if (x[1000] <= 30.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1480] <= 9.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1159] <= 4.5) {
                                            if (x[474] <= -9.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[323] <= 33.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1313] <= 11.5) {
                                        if (x[215] <= 22.5) {
                                            if (x[1300] <= -7.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[143] <= 20.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[920] <= 84.5) {
                                            if (x[1057] <= 36.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[559] <= 39.5) {
                                    if (x[1832] <= 39.0) {
                                        if (x[483] <= 41.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[266] <= 31.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1472] <= 40.5) {
                                            if (x[518] <= 32.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1764] <= 13.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[271] <= 73.5) {
                                        if (x[546] <= 49.5) {
                                            if (x[160] <= 29.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[789] <= 46.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1148] <= 53.5) {
                                if (x[641] <= 41.5) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #5
                        if (x[1594] <= 56.5) {
                            if (x[392] <= 42.5) {
                                if (x[150] <= 19.5) {
                                    if (x[595] <= 8.5) {
                                        if (x[1640] <= 13.5) {
                                            if (x[126] <= 2.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1951] <= 22.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1287] <= 19.5) {
                                            if (x[923] <= 31.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[854] <= 24.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[241] <= 58.0) {
                                        if (x[1335] <= 23.5) {
                                            if (x[1067] <= 15.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1402] <= 26.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1273] <= 52.5) {
                                            if (x[321] <= 51.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[4] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[678] <= 44.5) {
                                    if (x[1726] <= 22.5) {
                                        if (x[1680] <= 34.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[178] <= 11.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[991] <= 40.5) {
                                            if (x[1270] <= 53.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1505] <= 43.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1200] <= 84.0) {
                                        if (x[1246] <= 39.5) {
                                            if (x[1710] <= 55.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1095] <= 41.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1029] <= 53.5) {
                                votes[4] += 1;
                            }

                            else {
                                if (x[1891] <= 41.5) {
                                    if (x[1776] <= 43.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[1385] <= 49.5) {
                                        if (x[1729] <= 37.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[557] <= 56.5) {
                                                votes[4] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #6
                        if (x[1474] <= 56.5) {
                            if (x[1831] <= 41.5) {
                                if (x[1151] <= 11.5) {
                                    if (x[315] <= 6.5) {
                                        if (x[1760] <= 19.0) {
                                            if (x[160] <= 30.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[78] <= 6.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[351] <= 11.0) {
                                            if (x[1108] <= -2.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1800] <= 30.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[834] <= 10.5) {
                                        if (x[1246] <= 36.5) {
                                            if (x[270] <= 16.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1800] <= 65.0) {
                                            if (x[840] <= 20.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1325] <= 24.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1583] <= 40.5) {
                                    if (x[111] <= 40.5) {
                                        if (x[350] <= 37.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1634] <= 45.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[998] <= 51.5) {
                                            if (x[766] <= 19.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[65] <= 43.5) {
                                                votes[4] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1081] <= 84.0) {
                                        if (x[1782] <= 46.5) {
                                            if (x[709] <= 50.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[822] <= 44.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1231] <= 55.0) {
                                if (x[1274] <= 55.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[1468] <= 52.0) {
                                    if (x[1470] <= 62.0) {
                                        if (x[1108] <= 48.0) {
                                            votes[4] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #7
                        if (x[595] <= 59.5) {
                            if (x[1551] <= 41.5) {
                                if (x[1750] <= 16.5) {
                                    if (x[800] <= 27.5) {
                                        if (x[135] <= 9.5) {
                                            if (x[1880] <= 26.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[417] <= 23.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[995] <= 13.5) {
                                            if (x[596] <= 11.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1718] <= 11.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[27] <= 17.5) {
                                        if (x[1335] <= 19.5) {
                                            if (x[163] <= 9.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1382] <= 7.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1081] <= 63.5) {
                                            if (x[1943] <= 41.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1721] <= 46.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[981] <= 31.5) {
                                    if (x[1005] <= 17.5) {
                                        if (x[840] <= 38.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1909] <= 33.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[1063] <= 47.5) {
                                        if (x[950] <= 58.5) {
                                            if (x[1631] <= 50.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[386] <= 50.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1190] <= 50.0) {
                                            if (x[1769] <= 37.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1267] <= 51.5) {
                                if (x[1394] <= 27.0) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[1015] <= 36.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #8
                        if (x[1835] <= 59.5) {
                            if (x[1832] <= 41.5) {
                                if (x[1190] <= 18.5) {
                                    if (x[1276] <= -0.5) {
                                        if (x[1486] <= 2.5) {
                                            if (x[1806] <= 5.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[396] <= 7.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[399] <= -2.5) {
                                            if (x[1955] <= 1.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1360] <= 46.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1273] <= 10.5) {
                                        if (x[1887] <= 42.5) {
                                            if (x[1465] <= -5.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[36] <= -8.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1442] <= 57.0) {
                                            if (x[1842] <= 27.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[561] <= 59.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1304] <= 40.5) {
                                    if (x[871] <= 40.5) {
                                        if (x[1318] <= 43.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[1959] <= 47.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1266] <= 43.5) {
                                            if (x[1032] <= 41.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1036] <= 46.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1271] <= 50.5) {
                                        if (x[802] <= 50.5) {
                                            if (x[93] <= 34.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1879] <= 45.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1631] <= 74.5) {
                                            if (x[671] <= 53.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[505] <= 58.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[627] <= 51.5) {
                                votes[4] += 1;
                            }

                            else {
                                if (x[62] <= 51.5) {
                                    if (x[1757] <= 57.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[4] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #9
                        if (x[674] <= 56.5) {
                            if (x[235] <= 13.5) {
                                if (x[710] <= 17.5) {
                                    if (x[360] <= 14.5) {
                                        if (x[882] <= 22.5) {
                                            if (x[1729] <= 37.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[588] <= -9.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1035] <= 13.0) {
                                            if (x[390] <= 20.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1258] <= 10.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[82] <= 50.5) {
                                        if (x[1363] <= 12.0) {
                                            if (x[625] <= 9.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[288] <= 45.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[840] <= 80.5) {
                                    if (x[1311] <= 43.5) {
                                        if (x[638] <= 11.0) {
                                            if (x[1841] <= 39.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1920] <= 33.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[145] <= 45.5) {
                                            if (x[1079] <= 42.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[470] <= 53.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1919] <= 56.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[149] <= 54.5) {
                                if (x[1915] <= 58.5) {
                                    if (x[377] <= 46.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[1345] <= 47.0) {
                                    if (x[1670] <= 62.0) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[628] <= 48.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #10
                        if (x[1394] <= 56.5) {
                            if (x[711] <= 42.5) {
                                if (x[360] <= 60.5) {
                                    if (x[1590] <= 18.5) {
                                        if (x[1447] <= 29.5) {
                                            if (x[720] <= 22.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1675] <= 10.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[115] <= 15.5) {
                                            if (x[923] <= 11.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[897] <= 41.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[511] <= 33.5) {
                                        if (x[151] <= 35.5) {
                                            if (x[189] <= 35.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1080] <= 84.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[241] <= 62.0) {
                                            if (x[1064] <= 30.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[726] <= 31.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1677] <= 45.5) {
                                    if (x[511] <= 41.0) {
                                        if (x[1363] <= 50.0) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[320] <= 8.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[983] <= 42.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1789] <= 54.5) {
                                        if (x[761] <= 49.5) {
                                            if (x[630] <= 56.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[545] <= 49.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[47] <= 38.5) {
                                            if (x[1112] <= 54.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[728] <= 27.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1710] <= 57.5) {
                                if (x[824] <= 48.5) {
                                    votes[4] += 1;
                                }

                                else {
                                    if (x[1771] <= 54.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[1786] <= 51.0) {
                                    if (x[643] <= 54.0) {
                                        if (x[857] <= 48.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[4] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[65] <= 45.5) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }
                        }

                        // tree #11
                        if (x[278] <= 49.5) {
                            if (x[912] <= 42.5) {
                                if (x[1110] <= 18.5) {
                                    if (x[560] <= 20.5) {
                                        if (x[762] <= 21.5) {
                                            if (x[1486] <= 3.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[177] <= -4.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[756] <= 6.5) {
                                            if (x[835] <= 11.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1248] <= 27.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1075] <= 10.5) {
                                        if (x[1051] <= 28.0) {
                                            if (x[1163] <= 7.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[1720] <= 75.0) {
                                            if (x[1682] <= 26.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[706] <= 43.5) {
                                    if (x[1951] <= 41.5) {
                                        if (x[1815] <= 34.0) {
                                            if (x[212] <= 27.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[574] <= 35.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[309] <= 37.5) {
                                            if (x[1042] <= 37.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1486] <= 21.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[280] <= 94.0) {
                                        if (x[712] <= 45.5) {
                                            votes[3] += 1;
                                        }

                                        else {
                                            if (x[1392] <= 69.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[262] <= 41.5) {
                                if (x[1795] <= 58.5) {
                                    if (x[903] <= 43.5) {
                                        if (x[745] <= 39.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[3] += 1;
                                        }
                                    }

                                    else {
                                        if (x[744] <= 49.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[991] <= 64.5) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[941] <= 49.5) {
                                    if (x[165] <= 37.5) {
                                        if (x[991] <= 50.5) {
                                            if (x[997] <= 49.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1244] <= 41.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1715] <= 60.5) {
                                            if (x[707] <= 47.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            votes[4] += 1;
                                        }
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #12
                        if (x[674] <= 56.5) {
                            if (x[1672] <= 41.5) {
                                if (x[1870] <= 17.5) {
                                    if (x[520] <= 21.5) {
                                        if (x[442] <= 20.5) {
                                            if (x[1120] <= 19.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1155] <= 2.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1315] <= 11.5) {
                                            if (x[1486] <= 2.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1318] <= 13.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[280] <= 68.5) {
                                        if (x[815] <= 20.5) {
                                            if (x[121] <= 25.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1334] <= 40.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1720] <= 47.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            if (x[546] <= 42.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[1781] <= 38.5) {
                                    if (x[798] <= 47.5) {
                                        if (x[1312] <= 42.5) {
                                            if (x[1213] <= 26.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            if (x[791] <= 40.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1791] <= 47.5) {
                                            if (x[227] <= 42.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1285] <= 28.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[385] <= 48.5) {
                                        if (x[202] <= 43.5) {
                                            if (x[109] <= 52.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1939] <= 42.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1446] <= 60.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            if (x[651] <= 48.5) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1629] <= 57.0) {
                                if (x[1711] <= 61.5) {
                                    if (x[1230] <= 60.0) {
                                        votes[4] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }

                                else {
                                    if (x[1572] <= 38.0) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[586] <= 50.5) {
                                    if (x[1085] <= 41.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }
                        }

                        // tree #13
                        if (x[317] <= 45.5) {
                            if (x[712] <= 41.5) {
                                if (x[1710] <= 17.5) {
                                    if (x[1246] <= -5.0) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[1595] <= 10.0) {
                                            if (x[1886] <= -2.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[167] <= 25.0) {
                                                votes[1] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1193] <= 15.5) {
                                        if (x[1460] <= 22.5) {
                                            if (x[1800] <= 6.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }

                                    else {
                                        if (x[880] <= 74.5) {
                                            if (x[1921] <= 33.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[3] += 1;
                                            }
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }
                            }

                            else {
                                if (x[152] <= 42.5) {
                                    if (x[49] <= 23.5) {
                                        votes[3] += 1;
                                    }

                                    else {
                                        if (x[461] <= 45.5) {
                                            votes[0] += 1;
                                        }

                                        else {
                                            votes[1] += 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[238] <= 51.5) {
                                        if (x[160] <= 9.5) {
                                            if (x[327] <= 25.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[206] <= 20.0) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        votes[4] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            if (x[1788] <= 41.5) {
                                if (x[235] <= 57.5) {
                                    if (x[1678] <= 39.5) {
                                        votes[0] += 1;
                                    }

                                    else {
                                        if (x[262] <= 38.5) {
                                            if (x[1572] <= 42.0) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[302] <= 42.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    votes[4] += 1;
                                }
                            }

                            else {
                                if (x[585] <= 49.5) {
                                    if (x[109] <= 53.5) {
                                        if (x[1274] <= 56.5) {
                                            if (x[802] <= 48.5) {
                                                votes[3] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1115] <= 60.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[4] += 1;
                                            }
                                        }
                                    }

                                    else {
                                        if (x[1846] <= 37.5) {
                                            if (x[1367] <= 46.5) {
                                                votes[0] += 1;
                                            }

                                            else {
                                                votes[2] += 1;
                                            }
                                        }

                                        else {
                                            if (x[1154] <= 60.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[4] += 1;
                                            }
                                        }
                                    }
                                }

                                else {
                                    if (x[1222] <= 46.5) {
                                        if (x[234] <= 61.0) {
                                            if (x[1890] <= 38.0) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[0] += 1;
                                            }
                                        }

                                        else {
                                            votes[4] += 1;
                                        }
                                    }

                                    else {
                                        if (x[60] <= 41.5) {
                                            votes[2] += 1;
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }
                                }
                            }
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 5; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(const int8_t *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Ambiente ou Silêncio";
                            case 1:
                            return "Ambiente ou Silêncio";
                            case 2:
                            return "Bom";
                            case 3:
                            return "Mediano";
                            case 4:
                            return "Ruim";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }