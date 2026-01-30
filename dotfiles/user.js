/******
 * modified Arkenfox userJS for broller :)
******/
// 0000: disable about:config warning ***/
user_pref("browser.aboutConfig.showWarning", false);
/*** [SECTION 0100]: STARTUP ***/
// 0102: set startup page [SETUP-CHROME]
// user_pref("browser.startup.page", 1);
// 0104: set NEWTAB page
user_pref("browser.newtabpage.enabled", true);
// 0105: disable sponsored content on Firefox Home (Activity Stream)
user_pref("browser.newtabpage.activity-stream.showSponsored", false); // [FF58+]
user_pref("browser.newtabpage.activity-stream.showSponsoredTopSites", false); // [FF83+] Shortcuts>Sponsored shortcuts
// 0106: clear default topsites
user_pref("browser.newtabpage.activity-stream.default.sites", "https://intra.42.fr/,https://youtube.com,https://discord.com/app,https://twitter.com");
/*** [SECTION 0200]: GEOLOCATION ***/
// 0202: disable using the OS's geolocation service ***/
user_pref("geo.provider.ms-windows-location", false); // [WINDOWS]
user_pref("geo.provider.use_corelocation", false); // [MAC]
user_pref("geo.provider.use_geoclue", false); // [FF102+] [LINUX]
/** RECOMMENDATIONS ***/
// 0320: disable recommendation pane in about:addons (uses Google Analytics) ***/
user_pref("extensions.getAddons.showPane", false); // [HIDDEN PREF]
// 0321: disable recommendations in about:addons' Extensions and Themes panes [FF68+] ***/
user_pref("extensions.htmlaboutaddons.recommendations.enabled", false);
// 0322: disable personalized Extension Recommendations in about:addons and AMO [FF65+]
user_pref("browser.discovery.enabled", false);
// 0323: disable shopping experience [FF116+]
user_pref("browser.shopping.experience2023.enabled", false); // [DEFAULT: false]
/** TELEMETRY ***/
// 0330: disable new data submission [FF41+]
user_pref("datareporting.policy.dataSubmissionEnabled", false);
// 0331: disable Health Reports
user_pref("datareporting.healthreport.uploadEnabled", false);
user_pref("datareporting.healthreport.service.enabled", false);
// 0332: disable telemetry
user_pref("toolkit.telemetry.unified", false);
user_pref("toolkit.telemetry.enabled", false); // see [NOTE]
user_pref("toolkit.telemetry.server", "data:,");
user_pref("toolkit.telemetry.archive.enabled", false);
user_pref("toolkit.telemetry.newProfilePing.enabled", false); // [FF55+]
user_pref("toolkit.telemetry.shutdownPingSender.enabled", false); // [FF55+]
user_pref("toolkit.telemetry.updatePing.enabled", false); // [FF56+]
user_pref("toolkit.telemetry.bhrPing.enabled", false); // [FF57+] Background Hang Reporter
user_pref("toolkit.telemetry.firstShutdownPing.enabled", false); // [FF57+]
// 0333: disable Telemetry Coverage
user_pref("toolkit.telemetry.coverage.opt-out", true); // [HIDDEN PREF]
user_pref("toolkit.coverage.opt-out", true); // [FF64+] [HIDDEN PREF]
user_pref("toolkit.coverage.endpoint.base", "");
// 0335: disable Firefox Home (Activity Stream) telemetry ***/
user_pref("browser.newtabpage.activity-stream.feeds.telemetry", false);
user_pref("browser.newtabpage.activity-stream.telemetry", false);
/** STUDIES ***/
// 0340: disable Studies
user_pref("app.shield.optoutstudies.enabled", false);
// 0341: disable Normandy/Shield [FF60+]
user_pref("app.normandy.enabled", false);
user_pref("app.normandy.api_url", "");
/** CRASH REPORTS ***/
// 0350: disable Crash Reports ***/
user_pref("breakpad.reportURL", "");
user_pref("browser.tabs.crashReporting.sendReport", false); // [FF44+]
// 0351: enforce no submission of backlogged Crash Reports [FF58+]
user_pref("browser.crashReports.unsubmittedCheck.autoSubmit2", false); // [DEFAULT: false]
/** OTHER ***/
// 0360: disable Captive Portal detection
user_pref("captivedetect.canonicalURL", "");
user_pref("network.captive-portal-service.enabled", false); // [FF52+]
// 0361: disable Network Connectivity checks [FF65+]
user_pref("network.connectivity-service.enabled", false);
// 0401: disable SB (Safe Browsing) */
user_pref("browser.safebrowsing.downloads.remote.enabled", false);
user_pref("browser.safebrowsing.downloads.enabled", false);
/*** [SECTION 0600]: BLOCK IMPLICIT OUTBOUND [not explicitly asked for - e.g. clicked on] ***/
// 0601: disable link prefetching
user_pref("network.prefetch-next", false);
// 0602: disable DNS prefetching
user_pref("network.dns.disablePrefetch", true);
user_pref("network.dns.disablePrefetchFromHTTPS", true);

// Check if we finished

user_pref("extensions.pocket.enabled", false);
user_pref("browser.translations.enable", false);
user_pref("browser.translations.panelShown", false);
user_pref("privacy.fingerprintingProtection", true);
user_pref("privacy.resistFingerprinting", true);

user_pref("media.ffmpeg.vaapi.enabled", true);
user_pref("media.hardware-video-decoding.enabled", true);
user_pref("media.hardware-video-decoding.force-enabled", true);
user_pref("media.navigator.mediadecoder_vp8_hardware_enabled", true);
user_pref("media.navigator.mediadatadecoder_vp8_hardware_enabled", true);

user_pref("_user.js.finished", "Ooh. Lot quieter around here.");
