#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoSpotify.h>
#include <ArduinoSpotifyCert.h>

class SpotifyAPI : public ESPDeckModule {
    public:
        String lcdFirstRow;
        String lcdSecondRow;
        virtual void initialize(LiquidCrystal_I2C *lcdObject) override {
            _lcd = lcdObject;
            _client.setCACert(spotify_server_cert);
            _spotify.refreshAccessToken();
        }
        virtual void lcdRefresh() override {
            if (_refreshTime + 2000 < millis()) {
                Serial.println("Spotify call");
                _refreshTime = millis();
                _songInfo = _spotify.getCurrentlyPlaying();
                _lcd->clear();
                _lcd->setCursor(0,0);
                _lcd->print(_songInfo.firstArtistName);
                _lcd->setCursor(0,1);
                _lcd->print(_songInfo.trackName);
            }
        }
    private:
        long _refreshTime;
        const char* _spotifyClientId = SPOTIFYCLIENTID;
        const char* _spotifyClientSecret = SPOTIFYCLIENTSECRET;
        const char* _spotifyClientRefreshToken = SPOTIFYREFRESHTOKEN;
        WiFiClientSecure _client;
        LiquidCrystal_I2C *_lcd;
        CurrentlyPlaying _songInfo;
        ArduinoSpotify _spotify = ArduinoSpotify(_client,_spotifyClientId,_spotifyClientSecret,_spotifyClientRefreshToken);
};