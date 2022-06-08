#ifndef WIFICREDENTIALS_H
#define WIFICREDENTIALS_H

#include "WString.h"

struct WifiCredentials{
        String ssid;
        String password;
};

// class WifiCredentials{
//     private:
//         String _ssid;
//         String _password;
//     public:
//         WifiCredentials();
//         WifiCredentials(
//             String ssid,
//             String password
//         );
//         void set(
//             String ssid,
//             String password
//         );

//         WifiCredentials get();
//         String getSsid();
//         String getPassword();

// };
#endif 