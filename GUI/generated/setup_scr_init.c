/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_init(lv_ui *ui){

	//Write codes init
	ui->init = lv_obj_create(NULL, NULL);

	//Write codes init_label_1
	ui->init_label_1 = lv_label_create(ui->init, NULL);
	lv_label_set_text(ui->init_label_1, "Trying to connect to Wi-Fi...");
	lv_label_set_long_mode(ui->init_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->init_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for init_label_1
	static lv_style_t style_init_label_1_main;
	lv_style_reset(&style_init_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_init_label_1_main
	lv_style_set_radius(&style_init_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_init_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_init_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_init_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_init_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_init_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_init_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_20);
	lv_style_set_text_letter_space(&style_init_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_init_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_init_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_init_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_init_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->init_label_1, LV_LABEL_PART_MAIN, &style_init_label_1_main);
	lv_obj_set_pos(ui->init_label_1, 57, 94);
	lv_obj_set_size(ui->init_label_1, 208, 0);
}