void setupConfiguration() {
  setupConfigurationPages();
}

bool isDryGround() {
  return analogRead(SOIL_MOISTURE_SENSOR) > DRY_SIGNAL;
}