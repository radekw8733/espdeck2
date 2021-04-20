class ESPDeckModule {
    public:
        virtual void initialize(LiquidCrystal_I2C *lcdobject);
        virtual void lcdRefresh();
};