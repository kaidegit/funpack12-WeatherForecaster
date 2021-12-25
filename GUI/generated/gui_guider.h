/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *init;
	lv_obj_t *init_label_1;
	lv_obj_t *screen;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_skycon_label;
	lv_obj_t *screen_temp_label;
	lv_obj_t *screen_label_5;
	lv_obj_t *screen_humi_label;
	lv_obj_t *screen_label_6;
	lv_obj_t *screen_air_label;
	lv_obj_t *screen_label_7;
	lv_obj_t *screen_label_8;
	lv_obj_t *screen_first_temper_label;
	lv_obj_t *screen_first_air_label;
	lv_obj_t *screen_first_skycon_label;
	lv_obj_t *screen_label_12;
	lv_obj_t *screen_second_temper_label;
	lv_obj_t *screen_second_air_label;
	lv_obj_t *screen_second_skycon_label;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_third_temper_label;
	lv_obj_t *screen_third_air_label;
	lv_obj_t *screen_third_skycon_label;
	lv_obj_t *fail;
	lv_obj_t *fail_label_1;
	lv_obj_t *fail_label_2;
	lv_obj_t *fonts;
	lv_obj_t *fonts_label_1;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_init(lv_ui *ui);
void setup_scr_screen(lv_ui *ui);
void setup_scr_fail(lv_ui *ui);
void setup_scr_fonts(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif