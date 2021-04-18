#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoSpotify.h>
#include <ArduinoSpotifyCert.h>

class SpotifyAPI : public ESPDeckModule {
    public:
        virtual void initialize() override {
            _client.setCACert(spotify_server_cert);
        }
        virtual void lcdRefresh() override {
            
        }
    private:
        String _spotifyClientId = "";
        String _spotifyClientSecret = "";
        String _spotifyClientRefreshToken = "";
        WiFiClientSecure _client;
        ArduinoSpotify _spotify();
};