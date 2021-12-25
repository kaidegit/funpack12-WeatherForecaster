/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_fonts(lv_ui *ui){

	//Write codes fonts
	ui->fonts = lv_obj_create(NULL, NULL);

	//Write codes fonts_label_1
	ui->fonts_label_1 = lv_label_create(ui->fonts, NULL);
	lv_label_set_text(ui->fonts_label_1, "晴多云阴轻度雾霾中重小雨暴雪浮尘沙风");
	lv_label_set_long_mode(ui->fonts_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->fonts_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for fonts_label_1
	static lv_style_t style_fonts_label_1_main;
	lv_style_reset(&style_fonts_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_fonts_label_1_main
	lv_style_set_radius(&style_fonts_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_fonts_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_fonts_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_fonts_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_fonts_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_fonts_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_fonts_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_fonts_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_fonts_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_fonts_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_fonts_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_fonts_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->fonts_label_1, LV_LABEL_PART_MAIN, &style_fonts_label_1_main);
	lv_obj_set_pos(ui->fonts_label_1, 57, 82);
	lv_obj_set_size(ui->fonts_label_1, 100, 0);
}