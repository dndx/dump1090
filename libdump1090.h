#ifndef LIBDUMP1090_H
#define LIBDUMP1090_H

enum {
    ADDR_TYPE_ADS_B_ICAO = 1,
    ADDR_TYPE_ADS_B_OTHER = 2,
    ADDR_TYPE_ADS_R_ICAO = 3,
    ADDR_TYPE_ADS_R_OTHER = 4,
    ADDR_TYPE_TIS_B_ICAO = 5,
    ADDR_TYPE_TIS_B_OTHER = 6,
    ADDR_TYPE_UNKNOWN = 7,
};

enum {
    SPEED_IS_GS = 1,
    SPEED_IS_IAS = 2,
    SPEED_IS_TAS = 3,
};

typedef struct {
    uint32_t        addr; // always valid (Mode S msg can not have no addr)
    int32_t         altitude; // altitude_valid
    int32_t         gnss_delta; // gnss_delta_valid
    uint32_t        heading; // heading_valid
    uint32_t        speed; // speed_valid
    int32_t         vs; // vs_valid
    uint32_t        squawk; // squawk_valid
    const char     *callsign; // callsign_valid
    uint32_t        category; // category_valid
    double          lat; // pos_valid
    double          lon; // pos_valid
    uint32_t        nic; // pos_valid
    uint32_t        nacp; // nacp_valid
    uint8_t         on_ground; // airground_valid

    uint8_t         addr_type;
    uint8_t         altitude_valid;
    uint8_t         altitude_is_baro;
    uint8_t         gnss_delta_valid;
    uint8_t         heading_valid;
    uint8_t         heading_is_true;
    uint8_t         speed_valid;
    uint8_t         speed_src;
    uint8_t         vs_valid;
    uint8_t         squawk_valid;
    uint8_t         callsign_valid;
    uint8_t         category_valid;
    uint8_t         pos_valid;
    uint8_t         nacp_valid;
    uint8_t         airground_valid;
} traffic_t;

typedef void (*dump1090_on_traffic_msg)(void *inst, traffic_t *msg);

extern int dump1090_init(dump1090_on_traffic_msg cb, void *data);
extern void dump1090_process(char *buf, size_t len);

#endif /* !LIBDUMP1090_H */
