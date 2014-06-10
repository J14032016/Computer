;;; general setting
; set the default file path
(setenv "HOME" "D:/Program Files/Emacs/")
(setq default-directory "E:/study/Dropbox/study-files/workplace/")

;;; keybinding
(global-set-key (kbd "C-SPC") 'nil) ; unbind C-SPC to set mark
(global-set-key (kbd "M-SPC") 'set-mark-command) ; M-SPC set mark
(global-set-key [C-tab] 'other-window) ; C-tab switch to other windows
(require 'ibuffer) ; buffer
(global-set-key (kbd "C-x C-b") 'ibuffer)
(global-set-key (kbd "C-x C-k") 'kill-this-buffer) ; kill buffer
(global-set-key (kbd "RET") 'newline-and-indent) ; return indent
(global-set-key (kbd "<f12>") 'semantic-ia-fast-jump)
(global-set-key (kbd "M-p") 'semantic-ia-complete-symbol)


;;; compile function by mode
(defvar my-compile-hook nil)
(defun my-compile-main-fun ()
  (interactive)
  (run-hooks 'my-compile-hook))
(defun orginal-compile-fun ()
  (let ((mode major-mode)
        (compstr nil))
    (cond ((eql mode 'c-mode)
           (setq compstr (concat "gcc -g -Wall -o " (file-name-base) " "
                                 (buffer-file-name))))
          ((eql mode 'c++-mode)
           (setq compstr (concat "g++ -g -Wall -o " (file-name-base) " "
                                 (buffer-file-name))))
          ((eql mode 'java-mode)
           (setq compstr (concat "javac " (buffer-file-name))))
          ((eql mode 'perl-mode)
           (setq compstr (concat "perl -w " (buffer-file-name))))
          ((eql mode 'python-mode)
           (setq compstr (concat "python " (buffer-file-name)))))
    (save-buffer)
    (if compstr
        (compile compstr))))
(add-hook 'my-compile-hook 'orginal-compile-fun)
(global-set-key [(f5)] 'my-compile-main-fun)

(defvar my-run-hook nil)
(defun my-run-main-fun ()
  (interactive)
  (run-hooks 'my-run-hook))
(defun orginal-run-fun ()
  (let ((mode major-mode)
        (compstr nil))
    (cond ((eql mode 'c-mode)
           (setq compstr (concat (file-name-base) ".exe")))
          ((eql mode 'c++-mode)
           (setq compstr (concat (file-name-base) ".exe")))
          ((eql mode 'java-mode)
           (setq compstr (concat "java " (file-name-base)))))
    (if compstr
        (shell-command compstr))))
(add-hook 'my-run-hook 'orginal-run-fun)
(global-set-key [C-f5] 'my-run-main-fun)


;;; some comfortable setting
(prefer-coding-system 'utf-8) ; utf-8
(setq default-major-mode 'text-mode) 
(setq user-full-name "zqy") ; self information
(setq user-mail-address "zhangqianyi1997@gmail.com")
(setq inhibit-startup-message t) ; close start-up image
(setq ring-bell-function 'ignore) ; close ring bell
(fset 'yes-or-no-p 'y-or-n-p) ; treat y as yes and n as no
(setq-default indent-tabs-mode nil)
(setq-default c-basic-offset 4) ; tab setting								 
(setq-default tab-width 4)
(setq auto-save-default nil)
(setq make-backup-file nil); nil backup files
(setq-default make-backup-files nil)
(setq x-select-enable-clipboard t) ; enable clipboard
(setq frame-title-format 'buffer-file-name) ; show file-name on the margin
(run-with-idle-timer 1 nil 'w32-send-sys-command 61488) ; start-up fullscreen
;(split-window-horizontally) ; start-up split the window


(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(blink-cursor-mode nil)
 '(column-number-mode t)
 '(eshell-kill-processes-on-exit t)
 '(gdb-many-windows t)
 '(global-font-lock-mode t)
 '(ido-mode t nil (ido))
 '(mouse-avoidance-mode (quote animate) nil (avoid))
 '(scroll-bar-mode nil)
 '(semantic-mode t)
 '(send-mail-function (quote mailclient-send-it))
 '(speedbar-show-unknown-files t)
 '(tool-bar-mode nil))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil :background "darkslategrey" :foreground "wheat" :inverse-video nil :box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 113 :width normal :foundry "outline" :family "YaHei Consolas Hybrid")))))

;;; auto-complete config
(add-to-list 'load-path "~/.emacs.d/emacs-plugins/auto-complete")
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/emacs-plugins/auto-config/ac-dict")
(ac-config-default)


;;; yasnippet-config
(add-to-list 'load-path "~/.emacs.d/emacs-plugins/yasnippet")
(require 'yasnippet)
(yas/initialize)
(yas/load-directory "~/.emacs.d/emacs-plugins/yasnippet/snippets")


;;; w3m config
(add-to-list 'load-path "~/.emacs.d/emacs-plugins/emacs-w3m")
(add-to-list 'exec-path "~/.emacs.d/emacs-plugins/w3m")
(require 'w3m-load) 
(autoload 'w3m "w3m" "interface for w3m on emacs" t)
(setq w3m-command-arguments '("-cookie" "-F")) 
(setq w3m-use-cookies t); use cookies
(setq w3m-home-page "https://duckduckgo.com/"); home setting
(setq w3m-default-display-inline-images t); display image
(setq w3m-default-toggle-inline-images t)
(setq w3m-show-graphic-icons-in-header-line t); show icon
(setq w3m-show-graphic-icons-in-mode-line t)

;;; color theme config
(add-to-list 'load-path "~/.emacs.d/emacs-plugins/color-theme")
(require 'color-theme)
(color-theme-initialize)
(color-theme-gnome2)

;;; sr-speedbar
(add-to-list 'load-path "~/.emacs.d/")
(require 'sr-speedbar)
(setq sr-speedbar-right-side nil)
(setq sr-speedbar-width 25)
(global-set-key (kbd "<f4>") 'sr-speedbar-toggle)

;;; slime config
(setq inferior-lisp-program "~/SBCL/sbcl.exe")
(add-to-list 'load-path "~/.emacs.d/emacs-plugins/slime/")
(require 'slime)
(slime-setup '(slime-fancy))
(add-to-list 'ac-modes 'lisp-mode)
