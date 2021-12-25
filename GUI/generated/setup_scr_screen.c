/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_1, "天气状况");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_1
	static lv_style_t style_screen_label_1_main;
	lv_style_reset(&style_screen_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_1_main
	lv_style_set_radius(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_1, LV_LABEL_PART_MAIN, &style_screen_label_1_main);
	lv_obj_set_pos(ui->screen_label_1, 20, 20);
	lv_obj_set_size(ui->screen_label_1, 100, 0);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_2, "温度");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_2, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_2
	static lv_style_t style_screen_label_2_main;
	lv_style_reset(&style_screen_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_2_main
	lv_style_set_radius(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_2, LV_LABEL_PART_MAIN, &style_screen_label_2_main);
	lv_obj_set_pos(ui->screen_label_2, 20, 55);
	lv_obj_set_size(ui->screen_label_2, 68, 0);

	//Write codes screen_skycon_label
	ui->screen_skycon_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_skycon_label, "default");
	lv_label_set_long_mode(ui->screen_skycon_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_skycon_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_skycon_label
	static lv_style_t style_screen_skycon_label_main;
	lv_style_reset(&style_screen_skycon_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_skycon_label_main
	lv_style_set_radius(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_skycon_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_skycon_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_skycon_label, LV_LABEL_PART_MAIN, &style_screen_skycon_label_main);
	lv_obj_set_pos(ui->screen_skycon_label, 185, 20);
	lv_obj_set_size(ui->screen_skycon_label, 100, 0);

	//Write codes screen_temp_label
	ui->screen_temp_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_temp_label, "25");
	lv_label_set_long_mode(ui->screen_temp_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_temp_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_temp_label
	static lv_style_t style_screen_temp_label_main;
	lv_style_reset(&style_screen_temp_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_temp_label_main
	lv_style_set_radius(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_temp_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_temp_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_temp_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_temp_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_temp_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_temp_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_temp_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_temp_label, LV_LABEL_PART_MAIN, &style_screen_temp_label_main);
	lv_obj_set_pos(ui->screen_temp_label, 100, 55);
	lv_obj_set_size(ui->screen_temp_label, 50, 0);

	//Write codes screen_label_5
	ui->screen_label_5 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_5, "湿度");
	lv_label_set_long_mode(ui->screen_label_5, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_5, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_5
	static lv_style_t style_screen_label_5_main;
	lv_style_reset(&style_screen_label_5_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_5_main
	lv_style_set_radius(&style_screen_label_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_5_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_5_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_5_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_5_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_5, LV_LABEL_PART_MAIN, &style_screen_label_5_main);
	lv_obj_set_pos(ui->screen_label_5, 185, 55);
	lv_obj_set_size(ui->screen_label_5, 56, 0);

	//Write codes screen_humi_label
	ui->screen_humi_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_humi_label, "50");
	lv_label_set_long_mode(ui->screen_humi_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_humi_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_humi_label
	static lv_style_t style_screen_humi_label_main;
	lv_style_reset(&style_screen_humi_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_humi_label_main
	lv_style_set_radius(&style_screen_humi_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_humi_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_humi_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_humi_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_humi_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_humi_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_humi_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_humi_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_humi_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_humi_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_humi_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_humi_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_humi_label, LV_LABEL_PART_MAIN, &style_screen_humi_label_main);
	lv_obj_set_pos(ui->screen_humi_label, 250, 54);
	lv_obj_set_size(ui->screen_humi_label, 45, 0);

	//Write codes screen_label_6
	ui->screen_label_6 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_6, "空气质量");
	lv_label_set_long_mode(ui->screen_label_6, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_6, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_6
	static lv_style_t style_screen_label_6_main;
	lv_style_reset(&style_screen_label_6_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_6_main
	lv_style_set_radius(&style_screen_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_6_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_6_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_6_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_6_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_6, LV_LABEL_PART_MAIN, &style_screen_label_6_main);
	lv_obj_set_pos(ui->screen_label_6, 20, 90);
	lv_obj_set_size(ui->screen_label_6, 100, 0);

	//Write codes screen_air_label
	ui->screen_air_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_air_label, "100");
	lv_label_set_long_mode(ui->screen_air_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_air_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_air_label
	static lv_style_t style_screen_air_label_main;
	lv_style_reset(&style_screen_air_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_air_label_main
	lv_style_set_radius(&style_screen_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_air_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_air_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_air_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_air_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_air_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_air_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_air_label, LV_LABEL_PART_MAIN, &style_screen_air_label_main);
	lv_obj_set_pos(ui->screen_air_label, 185, 90);
	lv_obj_set_size(ui->screen_air_label, 100, 0);

	//Write codes screen_label_7
	ui->screen_label_7 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_7, "近日天气");
	lv_label_set_long_mode(ui->screen_label_7, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_7, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_7
	static lv_style_t style_screen_label_7_main;
	lv_style_reset(&style_screen_label_7_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_7_main
	lv_style_set_radius(&style_screen_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_7_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_7_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_7_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_7_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_7_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_7_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_7_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_7_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_7, LV_LABEL_PART_MAIN, &style_screen_label_7_main);
	lv_obj_set_pos(ui->screen_label_7, 0, 130);
	lv_obj_set_size(ui->screen_label_7, 100, 0);

	//Write codes screen_label_8
	ui->screen_label_8 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_8, "今天");
	lv_label_set_long_mode(ui->screen_label_8, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_8, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_8
	static lv_style_t style_screen_label_8_main;
	lv_style_reset(&style_screen_label_8_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_8_main
	lv_style_set_radius(&style_screen_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_8_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_8_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_8_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_8_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_8_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_8_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_8_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_8, LV_LABEL_PART_MAIN, &style_screen_label_8_main);
	lv_obj_set_pos(ui->screen_label_8, 20, 150);
	lv_obj_set_size(ui->screen_label_8, 70, 0);

	//Write codes screen_first_temper_label
	ui->screen_first_temper_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_first_temper_label, "default");
	lv_label_set_long_mode(ui->screen_first_temper_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_first_temper_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_first_temper_label
	static lv_style_t style_screen_first_temper_label_main;
	lv_style_reset(&style_screen_first_temper_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_first_temper_label_main
	lv_style_set_radius(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_first_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_first_temper_label, LV_LABEL_PART_MAIN, &style_screen_first_temper_label_main);
	lv_obj_set_pos(ui->screen_first_temper_label, 20, 170);
	lv_obj_set_size(ui->screen_first_temper_label, 70, 0);

	//Write codes screen_first_air_label
	ui->screen_first_air_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_first_air_label, "default");
	lv_label_set_long_mode(ui->screen_first_air_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_first_air_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_first_air_label
	static lv_style_t style_screen_first_air_label_main;
	lv_style_reset(&style_screen_first_air_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_first_air_label_main
	lv_style_set_radius(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_first_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_first_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_first_air_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_first_air_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_first_air_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_first_air_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_first_air_label, LV_LABEL_PART_MAIN, &style_screen_first_air_label_main);
	lv_obj_set_pos(ui->screen_first_air_label, 20, 190);
	lv_obj_set_size(ui->screen_first_air_label, 70, 0);

	//Write codes screen_first_skycon_label
	ui->screen_first_skycon_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_first_skycon_label, "default");
	lv_label_set_long_mode(ui->screen_first_skycon_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_first_skycon_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_first_skycon_label
	static lv_style_t style_screen_first_skycon_label_main;
	lv_style_reset(&style_screen_first_skycon_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_first_skycon_label_main
	lv_style_set_radius(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_first_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_first_skycon_label, LV_LABEL_PART_MAIN, &style_screen_first_skycon_label_main);
	lv_obj_set_pos(ui->screen_first_skycon_label, 20, 210);
	lv_obj_set_size(ui->screen_first_skycon_label, 70, 0);

	//Write codes screen_label_12
	ui->screen_label_12 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_12, "明天");
	lv_label_set_long_mode(ui->screen_label_12, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_12, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_12
	static lv_style_t style_screen_label_12_main;
	lv_style_reset(&style_screen_label_12_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_12_main
	lv_style_set_radius(&style_screen_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_12_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_12_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_12_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_12_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_12_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_12_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_12_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_12_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_12, LV_LABEL_PART_MAIN, &style_screen_label_12_main);
	lv_obj_set_pos(ui->screen_label_12, 120, 150);
	lv_obj_set_size(ui->screen_label_12, 70, 0);

	//Write codes screen_second_temper_label
	ui->screen_second_temper_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_second_temper_label, "default");
	lv_label_set_long_mode(ui->screen_second_temper_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_second_temper_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_second_temper_label
	static lv_style_t style_screen_second_temper_label_main;
	lv_style_reset(&style_screen_second_temper_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_second_temper_label_main
	lv_style_set_radius(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_second_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_second_temper_label, LV_LABEL_PART_MAIN, &style_screen_second_temper_label_main);
	lv_obj_set_pos(ui->screen_second_temper_label, 120, 170);
	lv_obj_set_size(ui->screen_second_temper_label, 70, 0);

	//Write codes screen_second_air_label
	ui->screen_second_air_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_second_air_label, "default");
	lv_label_set_long_mode(ui->screen_second_air_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_second_air_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_second_air_label
	static lv_style_t style_screen_second_air_label_main;
	lv_style_reset(&style_screen_second_air_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_second_air_label_main
	lv_style_set_radius(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_second_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_second_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_second_air_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_second_air_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_second_air_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_second_air_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_second_air_label, LV_LABEL_PART_MAIN, &style_screen_second_air_label_main);
	lv_obj_set_pos(ui->screen_second_air_label, 120, 190);
	lv_obj_set_size(ui->screen_second_air_label, 70, 0);

	//Write codes screen_second_skycon_label
	ui->screen_second_skycon_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_second_skycon_label, "default");
	lv_label_set_long_mode(ui->screen_second_skycon_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_second_skycon_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_second_skycon_label
	static lv_style_t style_screen_second_skycon_label_main;
	lv_style_reset(&style_screen_second_skycon_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_second_skycon_label_main
	lv_style_set_radius(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_second_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_second_skycon_label, LV_LABEL_PART_MAIN, &style_screen_second_skycon_label_main);
	lv_obj_set_pos(ui->screen_second_skycon_label, 120, 210);
	lv_obj_set_size(ui->screen_second_skycon_label, 70, 0);

	//Write codes screen_label_16
	ui->screen_label_16 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_16, "后天");
	lv_label_set_long_mode(ui->screen_label_16, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_16, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_16
	static lv_style_t style_screen_label_16_main;
	lv_style_reset(&style_screen_label_16_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_16_main
	lv_style_set_radius(&style_screen_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_16_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_16_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_16_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_16_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_16_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_label_16_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_16_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_16_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_16, LV_LABEL_PART_MAIN, &style_screen_label_16_main);
	lv_obj_set_pos(ui->screen_label_16, 230, 150);
	lv_obj_set_size(ui->screen_label_16, 70, 0);

	//Write codes screen_third_temper_label
	ui->screen_third_temper_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_third_temper_label, "default");
	lv_label_set_long_mode(ui->screen_third_temper_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_third_temper_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_third_temper_label
	static lv_style_t style_screen_third_temper_label_main;
	lv_style_reset(&style_screen_third_temper_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_third_temper_label_main
	lv_style_set_radius(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_third_temper_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_third_temper_label, LV_LABEL_PART_MAIN, &style_screen_third_temper_label_main);
	lv_obj_set_pos(ui->screen_third_temper_label, 230, 170);
	lv_obj_set_size(ui->screen_third_temper_label, 70, 0);

	//Write codes screen_third_air_label
	ui->screen_third_air_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_third_air_label, "default");
	lv_label_set_long_mode(ui->screen_third_air_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_third_air_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_third_air_label
	static lv_style_t style_screen_third_air_label_main;
	lv_style_reset(&style_screen_third_air_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_third_air_label_main
	lv_style_set_radius(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_third_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_third_air_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_third_air_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_third_air_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_third_air_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_third_air_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_third_air_label, LV_LABEL_PART_MAIN, &style_screen_third_air_label_main);
	lv_obj_set_pos(ui->screen_third_air_label, 230, 190);
	lv_obj_set_size(ui->screen_third_air_label, 70, 0);

	//Write codes screen_third_skycon_label
	ui->screen_third_skycon_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_third_skycon_label, "default");
	lv_label_set_long_mode(ui->screen_third_skycon_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_third_skycon_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_third_skycon_label
	static lv_style_t style_screen_third_skycon_label_main;
	lv_style_reset(&style_screen_third_skycon_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_third_skycon_label_main
	lv_style_set_radius(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_third_skycon_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_third_skycon_label, LV_LABEL_PART_MAIN, &style_screen_third_skycon_label_main);
	lv_obj_set_pos(ui->screen_third_skycon_label, 230, 210);
	lv_obj_set_size(ui->screen_third_skycon_label, 70, 0);
}